
#include<stdio.h>
#include<signal.h>


void handler(int num)
{

	if(num==SIGFPE)
	printf("sigmentation fault\n");
}

int main()
{
	if(signal(SIGFPE, handler)==SIG_ERR)
	{
		printf("unable to catch\n");
		exit(0);
	}
	int a=40/0;
	
	
}
