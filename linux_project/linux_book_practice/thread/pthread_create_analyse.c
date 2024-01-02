

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void* thread_function (void* thread_arg)
{
	fprintf(stderr,"child thread pid %d\n",(int)getpid());
}
int main ()
{
	pthread_t thread;
	
	fprintf(stderr,"main thread pid %d\n",(int)getpid());
	
	pthread_create (&thread, NULL, &thread_function, NULL);
	
	while(1);
	return 0;
}