

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

struct char_print_parms
{
	char character;
	
	int count;
};

void *char_print(void *parameter)
{
	
	struct char_print_parms *p=(struct char_print_parms*)parameter;
	
	int i;
	
	for(i=0;i<p->count;++i)
		fputc(p->character,stderr);
	return NULL;
	
}


int main()
{
	pthread_t id1,id2;
	
	struct char_print_parms arg1,arg2;
	
	arg1.character='x';
	arg1.count=30000;
	
	if(pthread_create(&id1,NULL,char_print,&arg1)!=0)
	{
		perror("unable to create thread1 \n ");
		exit(0);
	}
	arg2.character='0';
	arg2.count=20000;
	
	if(pthread_create(&id2,NULL,char_print,&arg2)!=0)
	{
		perror("unable to create thread2 \n ");
		exit(0);
	}
	
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	
	
	return 0;
}