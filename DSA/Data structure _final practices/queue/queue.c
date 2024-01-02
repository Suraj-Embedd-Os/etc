
#include<stdio.h>
#include<stdlib.h>
#include"queue.h"


void queue_printInt(void *x)
{
	printf("%d ", *(int *)x );
}
void queue_printFloat(void *x)
{
	printf("%f ", *(float *)x );
}
void queue_printChar(void *x)
{
	printf("%c ", *(char *)x );
}

int queue_Enqueue(Queue_t *q,void *item,size_t size)
{
	QNode_t *new_node=(QNode_t*)calloc(1,sizeof(QNode_t));
	
	new_node->item=calloc(1,size);
	new_node->next=NULL;
	
	for(int i=0;i<size;i++)
	{
	    *(char*)(new_node->item + i)=*(char*)(item+i);
	}
	
	if(q->rear == NULL)
	{
		q->rear=q->front = new_node;
		return 0;
	}
	q->front->next=new_node;
	q->front=q->front->next;
	
	return 0;
}

int queue_Dequeue(Queue_t *q,size_t size)
{
	void *item;
	item = calloc(1,size);
	
	for(int i=0 ;i<size;i++)
		*(char*)(item+i)=*(char*)(q->rear->item+i);
	
	QNode_t * temp =q->rear;
	q->rear=q->rear->next;
	
	free(temp);
	
	return *(int*)(item);
}

void queue_Display(Queue_t *q,void (*ptr)(void *))
{
	
	QNode_t * l1 =q->rear;
	
	while(l1)
	{
		(*ptr)(l1->item);
		l1=l1->next;
	}
	printf("\n");
}
