#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

struct foo
{
	int a,b,c;
};

void printfoo(char *s,struct foo *fp)
{
		printf("%s\n",s);
		printf("strcurture at 0x%lx\n",(unsigned long)fp);
		printf("foo.a %d\n",fp->a);
		printf("foo.b %d\n",fp->b);
		printf("foo.c %d\n",fp->c);
		
}

void *th_fun1 (void *args)
{
		struct foo s={1,2,3};
		printfoo("thread 1",&s);
		pthread_exit((void*)&s);
}
void *th_fun2 (void *args)
{
	
		printf("thread 2 id %ld\n",pthread_self());
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
	struct foo *fp;
	if(pthread_join(thid1, (void*)&fp)!=0)
	{
		perror("Can,t join  thread 1 \n");
						exit(0);
	}
					
	
	sleep(1);
	printf("parent starting second thread\n");
	
	if(pthread_create(&thid2, NULL,
                    th_fun2, NULL)!=0)
					{
						perror("Can,t create thread 2 \n");
						exit(0);
					}
	
	sleep(1);
	printfoo("parent",fp);
	exit(0);
	
}


