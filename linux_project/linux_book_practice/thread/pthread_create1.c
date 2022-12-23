

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void *print_xs(void *unused)
{
	
	while(1)
		fputc('x',stderr);
	return NULL;
	
}


int main()
{
	pthread_t id;
	
	if(pthread_create(&id,NULL,print_xs,NULL)!=0)
	{
		perror("unable to create thread \n ");
		exit(0);
	}
	
	while(1)
		fputc('o',stderr);
	
	return 0;
}