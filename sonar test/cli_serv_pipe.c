#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h> 
#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>




void client(int,int),server(int,int);
int main()
{
	
	int pipe1[2],pipe2[2];
	
	pid_t childPid;
	
	if(pipe(pipe1)<0 && pipe(pipe2)<0 )
	{
		perror("pipe1() pipe2()\n");
		exit(0);
	}
	
	if((childPid=fork())==0)
	{
		close(pipe1[1]); //clsoe write
		close(pipe2[0]);
		
		server(pipe1[0],pipe2[1]);
		exit(0);
	}
		close(pipe1[0]);
		close(pipe2[1]);
		
		client(pipe1[1],pipe2[0]);
		
		waitpid(childPid, NULL, 0);
		exit(0);

}

void client(int rdFd,int wrFd)
{
	char buff[1024];
	int len,n;
		printf("client \n");
	 //fgets(buff,1024,stdin);
	 scanf("%s",buff);
	 len=strlen(buff);
	 if(buff[len-1]=='\n')
		 len--;
	 
	 write(wrFd,buff,len);
	 
	 while((n=read(rdFd,buff,1024))>0)
		 write(fileno(stdout),buff,n);
	 
}

void server(int rdFd,int wrFd)
{
	char buff[1024];
	int len,n,fd;
	
	 if((n=read(rdFd,buff,1024))==0)
	 {
			perror("read()\n");
			exit(0);
	 }
		buff[n]='\0';
		
		if((fd=open(buff,O_RDONLY))<0)
		{
			snprintf(buff+n,sizeof(buff)-n,"cant open ,%s\n",strerror(errno));
			n=strlen(buff);
			write(wrFd,buff,n);
		}
		else
		{
			while((n=read(fd,buff,1024))>0)
				write(wrFd,buff,n);
			close(fd);
		}
		
	 
}


