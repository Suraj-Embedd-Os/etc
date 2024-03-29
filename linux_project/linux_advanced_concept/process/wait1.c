

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
 #include <sys/wait.h>

int spawn(char *program,char **arg_list)
{
	pid_t childPid;
	 /* Duplicate this process. */ 
	childPid=fork();
	
	if (childPid !=0)
	{
		 /* This is the parent process. */ 
		return childPid;
	}
	else
	{
		/* Now execute PROGRAM, searching for it in the path.  */ 
		execvp(program,arg_list);
		
		 /* The execvp  function returns only if an error occurs.  */ 
		fprintf(stderr,"an error occur in execvp\n");
		abort();
	}
}

int main(int argc,char *argv[])
{
	 int child_status;  
	  /*  The argument list to pass to the "ls" command.  */ 
	char *arg_list[] ={"ls","-la","/",NULL};
	
	/* Spawn a child process running the "ls" command. Ignore the       returned child process ID.  */    
	spawn ("ls", arg_list);  
 
	/* wait for child process */
	
	wait(&child_status);
	
	if(WIFEXITED(child_status))
	{
		 printf ("the child process exited normally, with exit code %d\n",WEXITSTATUS (child_status)); 
	}
	else
		 printf ("the child process exited abnormally\n"); 
	return 0;
}
