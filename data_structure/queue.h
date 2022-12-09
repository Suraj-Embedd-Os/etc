
#ifndef _QUEUE_H
#define _QUEUE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Queue
{
	int front;
	int rear;
	int size;
	int *Q;
};


void initialisedQueue(struct Queue *q_ptr,int size)
{
	q_ptr->front=q_ptr->rear=-1;
	q_ptr->size=size;
	q_ptr->Q=(int *)calloc(q_ptr->size,sizeof(int));
	
}

bool isEmptyQ(struct Queue *q_ptr)
{
   return (q_ptr->front==q_ptr->rear);
}

bool isFullQ(struct Queue *q_ptr)
{
    if((q_ptr->front+1)%q_ptr->size==q_ptr->rear%q_ptr->size)
    return true;
    else
    return false;
}

void enqueue(struct Queue *q_ptr,int data)
{
    
    if(q_ptr->front==-1 && q_ptr->rear==-1)
    {
        
        q_ptr->rear=0;
        q_ptr->front=0;
        q_ptr->Q[q_ptr->front]=data;
        q_ptr->front++;
        return;
        
    }
    else
    {
        if(!isFullQ(q_ptr))
        {
           q_ptr->Q[q_ptr->front]=data;
           q_ptr->front=1+q_ptr->front%q_ptr->size; 
        }
        else
        printf("Queue is full\n");
    }
}

void deque(struct Queue *q_ptr,int *item)
{
    if(!isEmptyQ(q_ptr))
    {
        if(item!=0)
            *item=q_ptr->Q[q_ptr->rear];
             q_ptr->rear=1+q_ptr->rear%q_ptr->size;
        
    }
    else
    {
         printf("Queue is empty\n");
    }
}

void displayQ(struct Queue *q_ptr)
{
    if(!isEmptyQ(q_ptr))
    {
        int i=0;
        for(i=q_ptr->rear; i!=q_ptr->front; i=1+i%q_ptr->size)
        {
            printf("%d %d\n",i,q_ptr->Q[i]);
        }
        printf("\n");
    }
    else
    {
         printf("Queue is empty\n");
    }
}






#endif

