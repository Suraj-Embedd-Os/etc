

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include"debug.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif


int main(int argc,char *argv[])
{
	int inputFd,outputFd,openFlags;
	mode_t filePerm;
	char buf[BUF_SIZE];
	ssize_t numRead;
	
	if(argc !=3 || strcmp(argv[1],"--help")==0)
	{
		DEBUG_LOG("usage error %s oldFile newFile ",argv[1]);
		return -1;
	}
	if((inputFd=open(argv[1],O_RDONLY))<0)
	{
		DEBUG_ERROR_LOG("inputFd ");
		return -1;
	}
	openFlags=O_CREAT|O_WRONLY|O_TRUNC;
	filePerm=S_IRWXU|S_IRUSR|S_IWUSR|S_IXUSR|S_IRWXG|S_IRGRP;
	
	if((outputFd=open(argv[2],openFlags,filePerm))<0)
	{
		DEBUG_ERROR_LOG("outputFd ");
		return -1;
	}
	
	while((numRead=read(inputFd,(char*)buf,BUF_SIZE))>0)
	{
		
		  if(write(outputFd,(char*)buf,numRead) !=numRead)
		  {
			  DEBUG_ERROR_LOG("write ");
			  return -1;
		  }
	}
	
	if(numRead==-1)
	{
		DEBUG_ERROR_LOG("read ");
		return -1;
	}
	
	if(close(inputFd)==-1)
	{
		DEBUG_ERROR_LOG("close inputFd ");
		return -1;
	}
	if(close(outputFd)==-1)
	{
		DEBUG_ERROR_LOG("close outputFd ");
		return -1;
	}
	
	
	return 0;
}
