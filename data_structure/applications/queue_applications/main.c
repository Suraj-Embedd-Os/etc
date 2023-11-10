

#include<stdio.h>
#include<stdlib.h>
#include "list/linkList.h"
#include "stack/stack.h"
#include "queue/queue.h"


int main()
{
	
	struct Queue *Q1=(struct Queue *)malloc(1*sizeof(struct Queue));
	printf("Queue appliation testing\n");
	enQueue(&Q1,10);
	enQueue(&Q1,100);
	enQueue(&Q1,1000);
	displayQ(&Q1);
	
	printf("Dequeue appliation %d \n",deQueue(&Q1));
	displayQ(&Q1);
	
	return 0;
}