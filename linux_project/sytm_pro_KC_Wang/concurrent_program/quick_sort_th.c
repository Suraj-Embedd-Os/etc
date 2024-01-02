#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

typedef struct
{
	int upperBound;
	int lowerBound;
}PARM;

#defien N 10

int A[N]={1,8,3,7,6,9,14,11,90,45};

int print()
{
	printf("[ ");
	for(int i=0;i<N;i++)
		printf("%d ",A[i]);
	printf("]\n");
	
	return 0;
}

int main()
{
	
	retrun 0;
}
