
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <fcntl.h>
 #include<string.h>
 #include<errno.h>


int main()
{
	int fd=open("testfile",O_RDONLY);
	char buff[100];
	int n=read(fd,buff,100);
	
	write(STDOUT_FILENO,buff,strlen(buff));
}
