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
	int pipe1[2],pipe2[2];
	pid_t childpid;
	
	if(pipe(pipe1)<0)
	{
		perror("pipe1 not created\n");
		exit(0);
	}
	
	if(pipe(pipe2)<0)
	{
		perror("pipe2 not created\n");
		exit(0);
	}
	
	if((childpid=fork())==0)
	{
		//child process
		close(pipe1[1]);
		close(pipe2[0]);
		
		server(pipe1[0],pipe2[1]);
		exit(0);

	}
	
	//parrent process
	close(pipe1[0]);
	close(pipe2[1]);
	
	client(pipe1[1],pipe2[0]);
	
	waitpid(childpid,NULL,0);
	
	return 0;
}


int server(int rdFd ,int wrFd)
{
	char buff[1000]={0};
	int n=0,fd;

	printf("server waiting for path name\n");
	if((n=read(rdFd,buff,1000))==0)
	{
		perror("server read() \n");
		exit(0);
	}
	buff[n]='\0';
	printf("server read  path name successfully %s\n",buff);
	if(fd=open(buff,O_RDONLY)<0){
		printf("failed to open \n");
		snprintf(buff+n,sizeof(buff)-n,": cant open file %s\n",strerror(errno));
		write(wrFd,buff,strlen(buff)-1);
	}
	else
	{
		memset(buff,0,1000);
		printf("read from file \n");
	//while((n=read(fd,buff,1000))>0)
		n=read(fd,buff,10);
	{
		printf("read data from file %s",buff);
		write(wrFd,buff,n);
		
	}
		close(fd);
	}
}

int client(int wrFd ,int rdFd)
{
	char buff[1000];
	
	int n;
	printf("enter path name :\n");
	fgets(buff,1000,stdin);
	
	if(write(wrFd,buff,strlen(buff)-1)<0)
	{
		perror("clien write() failed\n");
		exit(0);
	}
	printf("write path name successfully\n");
	memset(buff,0,1000);
	
	while(n=read(rdFd,buff,1000)>0){
		printf("read %s",buff);
		write(STDOUT_FILENO,buff,n);	
	}
}







