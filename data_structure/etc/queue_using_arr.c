

#include<stdio.h>
#include<stdlib.h>
#include"queue_using_arr.h"


int initialisedQueue(struct Queue **Q_ptr,int length)
{
	
	(*Q_ptr)->Q=(int*)malloc(length*sizeof(int));
	(*Q_ptr)->size=length;
	(*Q_ptr)->front=(*Q_ptr)->rear=-1;
	
	return 0;
}

int enqueue(struct Queue **Q_ptr,int data)
{
	//(*Q_ptr)->Q[++(*Q_ptr)->rear%(*Q_ptr)->size]=data;
	(*Q_ptr)->Q[0]=data;
	return 0;
}

int dequeue(struct Queue **Q_ptr)
{
	
	return(*Q_ptr)->Q[++(*Q_ptr)->front%(*Q_ptr)->size];
}

int isEmptyQueue(struct Queue **Q_ptr)
{
	
	if((*Q_ptr)->rear==-1 || (*Q_ptr)->rear%(*Q_ptr)->size==(*Q_ptr)->front%(*Q_ptr)->size)
		return 0;
	else
		return 1;
}

int isFullQueue(struct Queue **Q_ptr)
{
	if(((*Q_ptr)->rear%(*Q_ptr)->size+1)==(*Q_ptr)->front%(*Q_ptr)->size)
		return 1;
	else
		return 0;
}

void displayQueue(struct Queue **Q_ptr)
{
  struct Queue *temp= *Q_ptr;
  //printf("%d ",(*Q_ptr)->Q[0]);
  for(int i=(*Q_ptr)->front%(*Q_ptr)->size;i !=(*Q_ptr)->rear%(*Q_ptr)->size;i++)
  {
      printf("%d ",*((*Q_ptr)->Q+i+1));
  }
  printf("\n");
}




