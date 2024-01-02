# Import Module
import os

# Folder Path
path = r"./sweep_data"

# Change the directory
os.chdir(path)

# Read text File


def read_text_file(file_path):
	with open(file_path, 'r') as f:
		while True:
            line = f.readline()
            if not line: 
                break
            print(line)


# iterate through all file
for file in os.listdir():
	# Check whether file is in text format or not
	if file.endswith(".txt"):
		file_path = f"{path}\{file}"

		# call read text file function
		read_text_file(file_path)
        
        
 import os 
 
def yourProcessinglogic(UnPRocessedData): 
	. 
	. 
	. 
	return yourProcessedData 
 
for files in os.listdir('./sweep_data/'):
    if files.endswith(".txt"):
        with open(files,'r') as content: 
            while True:
                data = content.readlines()
                if not data:
                    break
                print(data)

import os
for filename in os.listdir(os.getcwd()):
   with open(os.path.join(os.getcwd(), filename), 'r') as f:
        while True:
                line = f.readline()
                if line=='': 
                    break
                print(line)
                

import os, glob
path = './sweep_data'
for filename in glob.glob(os.path.join(path, '*.txt')):
   with open(os.path.join(os.getcwd(), filename), 'r') as f:
         while True:
                line = f.readline()
                if line=='': 
                    break
                print(line)

