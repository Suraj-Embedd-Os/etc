
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#ifndef BUF_SIZE
#define BUF_SIZE  1024
#endif

int
main(int argc,char *argv[]){
	
	int inputFfd,outputFd,openFlasgs;
	
	mode_t filePerms;
	ssize_t numRead;
	char buff[BUF_SIZE];
	
	if(argc != 3 || strcmp(argv[1],"--help")==0){
		printf("%s oldFile newFile\n",argv[1]);
		return 0;
	}
	
	inputFfd=open(argv[1],O_RDONLY);
	if(inputFfd==-1)
	{
		perror("open\n");
		return 0;
	}
	
	openFlasgs =O_CREAT|O_WRONLY|O_TRUNC;
	filePerms =S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH;
	
	outputFd=open(argv[2],openFlasgs,filePerms);
	
	if(outputFd==-1)
	{
		perror("open\n");
		return 0;
	}
	
	while((numRead=read(inputFfd,buff,BUF_SIZE))>0){
		printf("read bytes %ld \n",numRead);
		if(write(outputFd,buff,numRead)!=numRead){
			perror("couldnt right whole buffer\n");
			return 0;
		}
	}
	
	if(numRead==-1){
		perror("read()\n");
		return 0;
	}
	
	if(close(inputFfd)==-1){
		perror("close() inputFfd\n");
		return 0;
	}
	
	if(close(outputFd)==-1){
		perror("close() outputFd\n");
		return 0;
	}
	
		
	
	
	
	return 0;
}