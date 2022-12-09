#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>

int globalVar=6;

int main()
{
	int var;
	pid_t pid;
	
	var=88;
	
	printf("befor vfork\n");
	
	if((pid=vfork())<0)
	{
		perror("vfork()\n");
		exit(0);
	}
	else if (pid==0)
	{
		globalVar++;
		var++;
		_exit(0);
	}
	
	printf("parent continue here ..\n");
	printf("pid = %ld ,glob =%d , var = %d \n",(long)getpid(), globalVar,var);
	
	return 0;
}

