#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>



void 
cleanup(void *arg)
{
	printf("cleanup :%s\n",(char*)arg);
}

void * fun1(void *arg)
{
	printf("thread 1 start\n");
	
	pthread_cleanup_push(cleanup,"thread 1 first handler");
	pthread_cleanup_push(cleanup,"thread 1 second handler");
	
	printf("thread 1 push complete\n");
	
	if(arg)
		return ((void*)1);
	
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	return ((void*)1);

	
}

void * fun2(void *arg)
{
	printf("thread 2 start\n");
	
	pthread_cleanup_push(cleanup,"thread 2 first handler");
	pthread_cleanup_push(cleanup,"thread 2 second handler");
	printf("thread 2 push complete\n");
	
	if(arg)
		pthread_exit((void*)2);
	
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	pthread_exit((void*)2);

	
}


int main()
{
	pthread_t thid1,thid2;
	 
	if(pthread_create(&thid1, NULL,fun1, (void *)1)!=0)
	{
		perror("thread 1 cant create\n");
		return 0;
	}
	if(pthread_create(&thid2, NULL,fun2, (void *)2)!=0)
	{
		perror("thread 2 cant create\n");
		return 0;
	}
	void *ret;
	
	if(pthread_join(thid1, &ret)!=0)
	{
		perror("thread 1 cant join\n");
		return 0;
	}	
	
	printf("Thread 1 return %ld\n",(long)ret);
	
	if(pthread_join(thid2, &ret)!=0)
	{
		perror("thread 2 cant join\n");
		return 0;
	}	
	
	printf("Thread 2 return %ld\n",(long)ret);
		
	
}



