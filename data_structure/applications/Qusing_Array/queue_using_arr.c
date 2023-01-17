
#include<stdio.h>
#include<stdlib.h>

#include"queue_using_arr.h"
#include"debug.h"

//#define DEBUG_LOG(args ...) 

//#define DEBUG_ERROR_LOG(args ...)

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
	(*Q_ptr)->data=(int*)malloc(length*sizeof(int));
	
	if((*Q_ptr)->data==NULL)
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

int enQueue(struct Queue **Q_ptr,int data)
{
	if(!isFullQueue(Q_ptr))
	{
		(*Q_ptr)->data[(*Q_ptr)->rear]=data;
		(*Q_ptr)->rear=((*Q_ptr)->rear+1)%(*Q_ptr)->length;
	
	return 0;
	}
	DEBUG_LOG("Queue overflow ");
	return -1;
}

int deQueue(struct Queue **Q_ptr)
{
	if(!isEmptyQueue(Q_ptr))
	{
		int _data;
		_data=(*Q_ptr)->data[(*Q_ptr)->front];
		(*Q_ptr)->front=((*Q_ptr)->front+1)%(*Q_ptr)->length;
		return _data;
	}
	DEBUG_LOG("Queue empty ");
	return -1;
	
}

int displayQueue(struct Queue **Q_ptr)
{
	struct Queue *temp=*Q_ptr;
	
	if(!isEmptyQueue(Q_ptr))
	{
	
    	for(int i=(temp->front)%(temp->length);i!=(temp->rear)%temp->length;i=(i+1)%temp->length)
    	{
    		printf("%d \n",temp->data[i]);
    	}
    	printf("\n");
    	return 0;
	}
	DEBUG_LOG("Queue empty ");
	return -1;
}





