
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

 
void handle_sigint(int sig)
{
	
	printf("CTR+C catch \n");
	exit(0);
}
void *PrintHello(void * id)
{
	while(1){
		printf("Thread %d: Hello World!\n", (int *)id);
		sleep(2);
	}
}

void main ()
{
	signal(SIGINT, handle_sigint);
	pthread_t thread0, thread1;
	pthread_create(&thread0, NULL, PrintHello, (void *) 0);
	pthread_create(&thread1, NULL, PrintHello, (void *) 1);
	
	pthread_exit(NULL);
	
}






#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static	int	glob=0;

pthread_mutex_t mtx =PTHREAD_MUTEX_INITIALIZER;

static	void *																		
threadFunc(void	*arg) 
{		
	int	loops=100000;
	int	loc,j;
	for	(j=0;j<loops;j++)
	{	
		//pthread_mutex_lock(&mtx);
		loc	=glob;						
		loc++;
		glob=loc;
		//pthread_mutex_unlock(&mtx);
	}
	return	NULL;
}



int main(int argc,char*argv[])
 {				
 pthread_t	t1,	t2;			
 int loops=1000,s;
				
	s=pthread_create(&t1,NULL,threadFunc,&loops);	
	if	(s!=0)	
		perror("pthread_create");	
	s=pthread_create(&t2,NULL,threadFunc,&loops);	
	if	(s!=0)			
		perror("pthread_create");
				
		s=pthread_join(t1,NULL);	
		if	(s!=0)		
			perror("pthread_join");
		s=pthread_join(t2,NULL);		
		if	(s!=0)				
		perror("pthread_join");
		printf("glob=%d\n",glob);		
		exit(EXIT_SUCCESS);
				
}
