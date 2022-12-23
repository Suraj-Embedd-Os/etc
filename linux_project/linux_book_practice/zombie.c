#include <sys/types.h>
#include<stdlib.h>
#include <unistd.h>
#include<stdio.h>



int main()
{

	if(fork()>0)
	{
		printf("parrent executing\n");
		//sleep(60);
		exit(0);
	}
	else
	{
		sleep(60);
		
	}
	return 0;
}


