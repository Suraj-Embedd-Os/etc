

#include<stdio.h>
#include<unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include<stdlib.h>
 #include<errno.h>
 #include<string.h>
 #include <fcntl.h>


int main()
{
	int fd1,fd2;
	
	fd1=open("pipe1",O_RDWR);
	fd2=open("pipe2",O_RDWR);
	char buf[100];
	
	if(fd1<0)
	{
		perror("fd1 open");
		exit(errno);
	}
	if(fd1<0)
	{
		perror("fd1 open");
		exit(errno);
	}
	
	printf("Reading data from pipe1\n");
	memset(buf,0,100);
	read(fd1,buf,100);
	
	printf("Data read from pipe1 %s \n",buf);
	memset(buf,0,100);
	printf("Reading data from pipe2\n");
	read(fd2,buf,100);
	
	
	printf("Data read from pipe2 %s \n",buf);
	
	return 0;
}



