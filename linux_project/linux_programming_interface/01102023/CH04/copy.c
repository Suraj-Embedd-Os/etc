
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif



int main(int argc , char *argv[])
{
	
	int inputFd, outFd;
	mode_t filePers;
	if(argc !=3 || strncmp(argc[1],"--help",6)){
		printf("Usaage errror OLD -File NEW -File \n");
		return -1;
	}
	
	filePers = 666;
	
	if(inputFd = open(argv[1],O_RDONLY)<0)
	{
		printf("Unable to open %s \n",argv[1]);
		return -1;
	}
	
	
	
	
		return 0;
}
