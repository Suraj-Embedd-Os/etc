
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <fcntl.h>


int main()
{
	
	int fd[2]={0};
	pid_t pid;
	char buff[]="hello form child\n";
	char read_buff[100];
	
	if(pipe(fd)<0)
	{
		perror("pipe()\n");
		exit(0);
	}
	
	if((pid=fork())<0)
	{
		perror("fork()\n");
		exit(0);
	}
	else if(pid>0)
	{
		close(fd[0]);
		write(fd[1],buff,sizeof(buff));
	}
	else 
	{
		close(fd[1]);
		int n=read(fd[0],read_buff,100);
		write(STDOUT_FILENO,read_buff,n-1);
	}
	
	exit(0);
	
		
}

