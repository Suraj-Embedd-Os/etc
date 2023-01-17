

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
 #include <fcntl.h>

int main()
{
	char str[20]="helllo world";
	char str2[20]={'\0'};
	
	int fd=open("temp.txt",O_WRONLY|O_CREAT);
	if(fd==-1)
	{
		printf("unable to open \n");
		exit(-1);
	}
	
	if((write(fd,str,strlen(str)+1))<0)
	{
		perror("write () ");
		exit(-1);
	}
	
	int flags;
	flags=fcntl(fd,F_GETFD);
	flags |=O_RDWR;
	
	if((fcntl(fd,F_SETFL,flags))==-1)
	{
		printf("fcntl to open \n");
		exit(-1);
	}
	
	if((read(fd,str2,20))<0)
	{
		perror("read ()");
		exit(-1);
	}
	
	if((write(1,str2,strlen(str2)+1))<0)
	{
		perror("read ()");
		exit(-1);
	}
	
	
	return 0;
}


