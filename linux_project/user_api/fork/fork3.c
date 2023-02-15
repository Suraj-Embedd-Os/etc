#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>



int main()
{
	pid_t pid;
	int childStatus;
	
	int k=10;
	
	
	printf("Current pid %d \n",getpid());
	getchar();
	
	
	pid=fork();
	
	
	
	if(pid==0)
	{
		//getchar();
		printf("child pid %d \n",getpid());
		k=44;
		printf("end of child %d \n",k);
		exit(100);
		//while(1);
	}	
	else
	{
		//getchar();
		printf("parent pid %d \n",getpid());
		printf("parent of k %d \n",k);
		
		wait(&childStatus);
		
		printf("end of parent %d \n",k);
		printf("child status %d \n",WEXITSTATUS(childStatus));
		//while(1);
	}
		
	return 0;
}
