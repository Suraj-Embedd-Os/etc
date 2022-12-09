#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>


int main()
{
	char buff[4096];
	int fd1,len,n,fd2;
	
	if((fd1=open("sweep_data.txt",O_RDONLY))<0)
	{
		perror("open\n");
		exit(0);
	}
	
	if((fd2=open("02_copy.img",O_WRONLY|O_CREAT|O_APPEND))<0)
	{
		perror("open\n");
		exit(0);
	}
	
	printf("file open succefully\n");
	while((n=read(fd1,buff,4096))>0)
		write(fd2,buff,n);
	
	//printf("%s",buff);
	
	close(fd1);
	close(fd2);
	
}
