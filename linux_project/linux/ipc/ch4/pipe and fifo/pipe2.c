#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <fcntl.h>
 #include<string.h>
 #include<errno.h>



int server(int ,int);
int client(int ,int);


int
main(int argc,char *argv[])
{
	int fd[2];
	pid_t childpid;
	char c;
	int n;
	
	if(pipe(fd)<0)
	{
		perror("pipe not created\n");
		exit(0);
	}
	
	
	if((childpid=fork())==0)
	{
		sleep(3);
		//child process
		if((n=read(fd[0],&c,1))!=1)
		{
			perror("read error");
			exit(0);
		}
		printf("child read %c\n",c);
		
		write(fd[0],"c",1);
		exit(0);

	}
	
		write(fd[1],"p",1);	
		if((n=read(fd[1],&c,1))!=1)
		{
			perror("read error");
			exit(0);
		}
		printf("parent read %c\n",c);
		waitpid(childpid,NULL,0);
	
	
	return 0;
}










