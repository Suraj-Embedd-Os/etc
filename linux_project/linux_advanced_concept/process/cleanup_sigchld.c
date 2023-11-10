
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>


sig_atomic_t child_wait_status;

void clean_up_child_process(int sig_no)
{
	if(sig_no == SIGCHLD)
	{
		printf("child process cleanup\n");
		int status;
		wait(&status);
		child_wait_status=status;
	}
	
}

int main()
{
		   
	struct sigaction sa;
	memset(&sa,0,sizeof(sa));
	sa.sa_handler=&clean_up_child_process;
	sigaction(SIGCHLD, &sa,NULL);
	
	pid_t child_pid;
	
	child_pid=fork();
	
	if(child_pid != 0)
	{
		for(int i=0;i<30;i++)
		{
			printf("parent..\n");
			sleep(1);
		}
		printf("child process exit status %d\n",child_wait_status);
	}
	else
	{
		printf("child process exited..\n");
		exit(0);
	}
	return 0;
}
