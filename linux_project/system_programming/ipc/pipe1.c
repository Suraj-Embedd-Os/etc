

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#define BUFF_SIZE	1024

char message[BUFF_SIZE];
char readmsg[BUFF_SIZE];
int fd[2];

void operation()
{
	printf("Write to pipe message is - %s ",message);
	write(fd[1],message,BUFF_SIZE);
	
	read(fd[0],readmsg,BUFF_SIZE);
	printf("read from pipe message is - %s ",readmsg);

}


int main()
{
		
		
	if(pipe(fd)<0)
	{
			perror("pipe()");
			exit(0);
	}
	printf("Enter a message to write to pipe\n");
	printf("to exit type \"quit\" \n");
	
	fgets(message,BUFF_SIZE,stdin);
	
	while(strcmp(message,"quit\n")!=0)
	{
		operation();
		fgets(message,BUFF_SIZE,stdin);
	}
}