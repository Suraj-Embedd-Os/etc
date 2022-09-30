#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>



void *th_fun1 (void *args)
{
	
		printf("thread 1 to returning\n");
		return ((void*)1);
}
void *th_fun2 (void *args)
{
	
		printf("thread 2 to exit\n");
		pthread_exit((void*)2);
}

int main()
{ 
	pthread_t thid1,thid2;
	if(pthread_create(&thid1, NULL,
                    th_fun1, NULL)!=0)
					{
						perror("Can,t create thread 1 \n");
						exit(0);
					}
					
	if(pthread_create(&thid2, NULL,
                    th_fun2, NULL)!=0)
					{
						perror("Can,t create thread 2 \n");
						exit(0);
					}
	void * retval;
	if(pthread_join(thid1, &retval)!=0)
	{
		perror("Can,t join  thread 1 \n");
						exit(0);
	}
	printf("thread 1 exit code %ld",(long)retval);
	
	if(pthread_join(thid2, &retval)!=0)
	{
		perror("Can,t join  thread 2 \n");
						exit(0);
	}
	printf("thread 2 exit code %ld",(long)retval);
	
	exit(0);
	
}


