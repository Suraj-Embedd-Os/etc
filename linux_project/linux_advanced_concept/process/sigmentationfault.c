

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include <stdlib.h>

void handler (int num)
{
	printf("catch signal %d\n",num);
	abort();
	
}


int main()
{
	 
	signal(SIGSEGV ,  handler);
	int *ptr=NULL;
	*ptr=10;
	
	return 0;
}
