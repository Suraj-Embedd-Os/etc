********************************************configuration*************************************************************
//Add your name to the global Git configuration
git config --global user.name "Your Name" 

//Add your email address to the global Git configuration
git config --global user.email  "Your E-mail Address"

//Display all the Git configurations
git config --list 

//Display the user.name configuration value
git config user.name 
git config user.email 

//Ask Git for help about its help system
git help help 
git help -a  			#Print all available Git commands
git --paginate help -a  #Paginate the display of all Git commands
git help -g 			#Print all available Git guides
git help glossary 		#Display the Git glossary

******************************************commit***************************************************************
// Commit changes with the log message entered on command line via the -m switch
git commit -m "Message"

//Show any changes between the tracked files in the current directory and the repository
git diff 

//Perform a git add, and then a git commit with the supplied log message
git commit -a -m "Message" 

//Show any changes between the staging area and the repository
git diff --staged 

//Show what git add would do
git add --dry-run . 

//Add all new files in the current directory (use git status afterward to see what was added)
git add . 

//Show history using one line per commit, and listing each file changed per commit
git log --shortstat --oneline 

************************************************operation staging*********************************************************
//Remove file from staging area
git rm file 

//Rename file1 to file2 in the staging area
git mv file1 file2 

//Pick parts of your changes to add to the staging area
git add -p 

//Reset your staging area, removing any changes you’ve added with git add
git reset file 

//Check out the latest committed version of the file into your working directory
git checkout file 

**************************************************git log *******************************************************
//Show the history, displaying the parent commit’s SHA1 ID for each commit.
git log --parents 

git log --parents --abbrev-commit 			#Same as the preceding command, but shorten the SHA1 ID.
git log --oneline  							#Display history concisely, using one line per each commit.

git log --patch 							#Display the history, showing the file differences between each commit.
git log --stat 								#Display the history, showing a summary of the file changes between each commit.
git log --patch-with-stat 					#Display the history, combining patch and stat output.
git log --oneline 							#file_one Display the history for file_one.
git rev-parse 								#Translate a branch name or a tag name to a specific SHA1 ID.
git checkout YOUR_SHA1ID 					#Change your working directory to match the version specified in YOUR_SHA1ID.

git tag TAG_NAME -m "MESSAGE" YOUR_SHA1ID	#Create a tag named TAG_NAME, pointing to YOUR_SHA1ID.
											 The tag will have a short MESSAGE associated with it. git tag List all tags.
git show TAG_NAME 							#Show information about the tag named TAG_NAME.


**********************************************chapter 9***********************************************************

git branch 				#List all branches.
git branch dev 			#Create a new branch named dev. (This branch points to the same commit as HEAD.)
git checkout dev 		#Change your working directory to the branch named dev.
git branch -d master 	#Delete the branch named master.

//View history of the repository across all branches
git log --graph --decorate--pretty=oneline --all --abbrev-commit 

//Make an alias named lol for the git log command in the previous row (see the Above and Beyond sidebar).
git config --global alias.lol "log --graph --decorate --pretty=oneline --all --abbrev-commit"

git branch -v 			#List all branches with SHA1 ID information.
git branch fixing_readme YOUR_SHA1ID 	#Make a branch using YOUR_SHA1ID as thestarting point.

//Make a branch named another_fix_branch using branch fixing_readme as the starting point.
git checkout -b another_fix_branch fixing_readme

git reflog 				#Show a record of all the times you changed branches (via git checkout).

//Set the current work in progress (WIP) to astash (holding area), so you can perform a gitcheckout.
git stash 
git stash list 			#List works in progress that you’ve stashed away.

//Apply the most recently saved stash to the current working directory; remove it from the stash
git stash pop 			

**********************************************chapter 10 Merging***********************************************************

//Indicate the difference between BRANCH1 and BRANCH2 relative to when they first became different.
git diff BRANCH1...BRANCH2 

//Summarize the difference between BRANCH1 and BRANCH2, by listing each file and its status.
git diff --name-status BRANCH1...BRANCH2

//Merge BRANCH2 into the current branch that you’re on.
git merge BRANCH2 

// A shorthand for git log -n 1 (show only the most recent commit).
git log -1

git mergetool 							#Open a tool to help perform a merge between two conflicted branches.
git merge --abort 						#Abandon a merge between two conflicted branches.
git merge-base BRANCH1 BRANCH2 			#Show the base commit between BRANCH1 and BRANCH2.

**********************************************chapter 11 Cloning***********************************************************

//Clone the Git repository at source to the destination_dir.
git clone source destination_dir 

//Display all commit log entries from all branches.(Normally, git log displays only entries from the
//current branch.)
git log --oneline --all 	

//Display the history in a simplified form.					
git log --simplify-by-decoration --decorate --all --oneline 
 
git branch --all 						#Show remote-tracking branches in addition to local branches.

//Clone the bare directory of the source repository into the destination_dir. By convention, destination_dir should end with .git.
git clone --bare source destination_dir

git ls-tree HEAD 						#Display all the files for HEAD (the current branch).

**********************************************chapter 12 colabrating with remote***********************************************************



