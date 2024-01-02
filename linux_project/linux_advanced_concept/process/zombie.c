

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>


int main(int argc,char *argv[])
{

	pid_t child_pid;
	
	child_pid=fork();
	
	if(child_pid != 0)
	{
		int ch_status;
		for(int i=0;i<10;i++)
		{
			printf("parent..\n");
			sleep(1);
		}
		
	}
	else
	{
		printf("child exited..\n");
		sleep(5);
		exit(0);
	}
	
	return 0;
}
