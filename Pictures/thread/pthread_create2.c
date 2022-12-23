
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>

static pthread_cond_t threadDied=PTHREAD_COND_INITIALIZER;
static pthread_mutex_t threadMutex=PTHREAD_MUTEX_INITIALIZER;

static int totThreads=0; //total thread created	
static int numLive=0; //number of thread alive
static	int	numUnjoined=0;

/*	Thread	states	*/
enum tstate	{					
TS_ALIVE/*	Thread	is	alive	*/			
TS_TERMINATED,/*	Thread	terminated,	not	yet	joined	*/		
TS_JOINED/*	Thread	terminated,	and	joined	*/
};

static struct{ /*	Info	about	each	thread	*/				
pthread_t tid;/*	ID	of	this	thread	*/				
enum tstate state;/*	Thread	state	(TS_*	constants	above)	*/			
int	sleepTime;/*	Number	seconds	to	live	before	terminating	*/
}*thread;	


static void *threadFunc(void *arg)
{
	int idx=((int)arg);
	int s;
	
	sleep(thread[idx].sleepTime);
	printf("Thread %d terminating\n",idx);
	
	s=pthread_mutex_lock(&threadMutex);
	if(s!=0)
		perror("mutex_lock\n");
	
	numUnjoined++;
	
	thread[idx].state=TS_TERMINATED;
	
	s=pthread_mutex_unlock(&threadMutex);
	if(s!=0)
		perror("mutex_unlock\n");
	
	s=pthread_cond_signal(&threadDied);
	if(s!=0)
		perror("threadDied\n");
	
	return NULL;
}


int main(int argc,char *argv[])
{
	int idx,s;

		if(argc<2 ||strcmp(argv[1]=="--help")==0)
		printf("%s ussage \n",argv[0]);
	
		thread=calloc(1,sizeof(*thread));
	
		for(idx=0;idx<argc-1;idx++)
		{
			thread[idx].state=
			s=pthread_create(&thread[idx].tid,NULL,threadFunc,&idx);
			if(s!=0)
			perror("pthread_create\n");
		}
	
	totThreads =argc-1;
	numLive=totThreads;
	
	while(numLive>0)
	{
		s=pthread_mutex_lock(&threadMutex);
		if(s!=0)
		perror("mutex_lock\n");
		
	while(numUnjoined==0)
		{
			s=pthread_cond_wait(&threadDied,&threadMutex);
			if(s!=0)
			perror("pthread_cond_wait\n");
		}
	
	for(idx=0;idx<totThreads;idx++)
	{
		if(thread[idx].state=TS_TERMINATED)
		{
		s=pthread_join(thread[idx].tid,NULL);
		if(s!=0)
			perror("pthread_join\n");
		thread[idx].state=TS_JOINED;
		numLive--;
		numUnjoined--;
		
		printf("Reaped	thread	%d	(numLive=%d)\n",idx,numLive);
		}
		
	}
		s=pthread_mutex_unlock(&threadMutex);
		if(s!=0)
		perror("mutex_unlock\n");
	}
	
	return 0;
	
}

