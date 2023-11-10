#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

#define N 4
int A[N][N],sum[N];

void *func(void *args)
{
	int j,row;
	pthread_t tid = pthread_self();
	row =(int*)args;
	printf("Thread %d [%lu] computes sum of row %d\n", row, tid, row); 
	for(j=0;j<N;j++)
		sum[row] +=A[row][j];
	
	printf("Thread %d [%lu] done: sum[%d] = %d\n", row, tid, row, sum[row]);
	pthread_exit((void*)0);
}

int main()
{
	pthread_t thread[N];
	int total=0;
	
	void *status;
	printf("Main initialised A matrix\n");
	for(int i=0;i<N;i++)
	{
		sum[i]=0;
		for(int j=0;j<N;j++)
		{
			A[i][j]=i*N+j+1;
			printf("%4d ",A[i][j]);
		}
		printf("\n");
	}
	
	printf("Main created  A thread\n");
	for(int i=0;i<N;i++)
	{
		if(pthread_create(&thread[i],NULL,func,(void*)i) != 0)
		{
			perror("pthread_create()");
			return -1;
		}
			
	}
	
	printf("main try to join thread\n");
	for(int i=0;i<N;i++)
	{
		if(pthread_join(thread[i],status) != 0)
		{
			perror("pthread_create()");
			return -1;
		}
		printf("Main: joined with %d [%lu]: status=%d\n", i, thread[i], (int)status);

	}
	
	printf("Main: compute and print total sum: ");
	for (int i=0; i<N; i++) 
		total += sum[i]; 
	printf("tatal = %d\n", total); 
	pthread_exit(NULL);

		
	return 0;
}
