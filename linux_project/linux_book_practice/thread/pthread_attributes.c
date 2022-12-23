

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void* thread_function (void* thread_arg)
{
	int x=0;
	while(1){
	fputc('x',stderr);
	x++;
	sleep(1);
	if(x==10)
		break;
	}
	return NULL;
}
int main ()
{
	pthread_attr_t attr;
	pthread_t thread;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
	pthread_create (&thread, &attr, &thread_function, NULL);
	
	while(1){
	fputc('0',stderr);
	sleep(1);
	}
	pthread_attr_destroy (&attr);
	return 0;
}