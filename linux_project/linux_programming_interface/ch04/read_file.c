

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>


int main(int argc,char *argv[])
{
	int inFd,outFd;
	char buff[100];
	
	inFd=open(argv[1],O_RDONLY);
	outFd=open(argv[2],O_WRONLY|O_CREAT);
	
	if(inFd==-1)
	{
		printf("unable to open\n");
		exit(-1);
	}
	int size=0;
	while((size=read(inFd,(char*)buff,100))>0)
	{
		write(outFd,buff,size);
	}
	
		return 0;
}

