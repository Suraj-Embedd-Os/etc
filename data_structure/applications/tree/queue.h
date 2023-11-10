
#ifndef __QUEUE_USING_ARR_
#define __QUEUE_USING_ARR_

#include<stdio.h>
#include<stdlib.h>

#include"debug.h"

struct Node
{
   struct Node *lchild;
   int data;
   struct Node *rchild;
};


struct Queue
{
	struct Node **Q;
	int length;
	int front;
	int rear;
	
};

int initialisedQueue(struct Queue **Q_ptr,int length);
int isEmptyQueue(struct Queue **Q_ptr);
int isFullQueue(struct Queue **Q_ptr);

int enQueue(struct Queue **Q_ptr,struct Node * node);
struct Node *  deQueue(struct Queue **Q_ptr);



int initialisedQueue(struct Queue **Q_ptr,int length)
{
	if(*Q_ptr==NULL)
	{
		*Q_ptr=(struct Queue *)malloc(1*sizeof(struct Queue));
		if(*Q_ptr==NULL)
		{
			DEBUG_ERROR_LOG("unable to create");
			return -1;
		}
	}
	(*Q_ptr)->Q=(struct Node**)malloc(length*sizeof(struct Node));
	
	if((*Q_ptr)->Q==NULL)
	{
		DEBUG_ERROR_LOG("unable to create");
		return -1;
	}
	
	(*Q_ptr)->length=length;
	(*Q_ptr)->front=(*Q_ptr)->rear=0;
	
	return 0;
}

int isEmptyQueue(struct Queue **Q_ptr)
{
	return ((*Q_ptr)->front==(*Q_ptr)->rear);
}

int isFullQueue(struct Queue **Q_ptr)
{

	return (((*Q_ptr)->front%(*Q_ptr)->length==((*Q_ptr)->rear+1)%(*Q_ptr)->length));
}

int enQueue(struct Queue **Q_ptr,struct Node * node)
{
	if(!isFullQueue(Q_ptr))
	{
		(*Q_ptr)->Q[(*Q_ptr)->rear]=node;
		(*Q_ptr)->rear=((*Q_ptr)->rear+1)%(*Q_ptr)->length;
	
	return 0;
	}
	DEBUG_LOG("Queue overflow ");
	return -1;
}

struct Node *  deQueue(struct Queue **Q_ptr)
{
	if(!isEmptyQueue(Q_ptr))
	{
		struct Node * _data;
		_data=(*Q_ptr)->Q[(*Q_ptr)->front];
		(*Q_ptr)->front=((*Q_ptr)->front+1)%(*Q_ptr)->length;
		return _data;
	}
	DEBUG_LOG("Queue empty ");
	return NULL;
	
}





#endif