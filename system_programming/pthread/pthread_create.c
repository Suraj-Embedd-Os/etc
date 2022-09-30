#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void *customThreadFunction()
{
	 for(int i = 0; i < 15; i++)
	 {
		printf("I am a Custom Thread Function Created ByProgrammer.\n");
		sleep(1);
	 }
	 return NULL;
}


int main()
{
	pthread_t thread;
	int status;
	status = pthread_create(&thread, NULL, customThreadFunction, NULL);
 
	 if(!status)
	 {
	  printf("Custom Created Successfully.\n");
	 }else
	 {
		printf("Unable to create the Custom Thread.\n");
		return 0;
	 }
	 
	for(int i = 0; i < 15; i++)
	{
	 printf("I am the process thread created by compiler Bydefault.\n");
	 sleep(1);
	}
 return 0;
	
}


