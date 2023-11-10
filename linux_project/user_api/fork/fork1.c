#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>



int main()
{
	pid_t pid;
	
	pid=fork();
	
	printf("Current pid %d \n",getpid());
	
	if(pid==0)
	{
		printf("child pid %d \n",getpid());
		while(1);
	}	
	else
	{
		getchar();
		printf("parent pid %d \n",getpid());
	}
		
	return 0;
}
