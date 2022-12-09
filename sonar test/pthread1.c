#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
pthread_t thid;

void printfIds(const char *str)
{
	pid_t pid;
	pthread_t tid;
	
	pid=getpid();
	tid=pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n",str,(unsigned long)pid,(unsigned long)tid,(unsigned long)tid);
}

void *th_fun (void *args)
{
	
		printfIds("new thread,");
		return ((void*)0);
}

int main()
{ 
	
	if(pthread_create(&thid, NULL,
                    th_fun, NULL)!=0)
					{
						perror("Can,t create thread \n");
						exit(0);
					}
		
	printfIds("main thread, ");
	sleep(1);
	exit(0);
	
}


