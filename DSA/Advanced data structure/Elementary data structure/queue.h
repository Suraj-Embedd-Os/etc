

#include<stdio.h>
#include<stdlib.h>

#include "stack.h"

enum
{
	ARRAY,
	LINKLIST,
	CIRCULAR_LIST
};

#define Q_IMPLEMENTATION 1

#if Q_IMPLEMENTATION == ARRAY
/*******************************************************************************************/
typedef struct 
{
    int front;
    int rear;
    itme_t *base;
    int size;
}queue_t;

queue_t *queue_create(int size)
{
   queue_t *Q=(queue_t*)calloc(1,sizeof(queue_t));
   Q->base=(itme_t*)calloc(size,sizeof(itme_t));
   
   Q->front=Q->rear=0;
   Q->size = size;
   
   return Q;
   
}

int is_empty_queue(queue_t **Q)
{
    return ((*Q)->front == (*Q)->rear);
}



int enqueue(queue_t **Q,itme_t x)
{
    if((*Q)->front != ((*Q)->rear+1)%(*Q)->size)
    {
        (*Q)->base[((*Q)->rear)%(*Q)->size]=x;
        (*Q)->rear=((*Q)->rear+1)%(*Q)->size;
        return 0;
    }
    else
    return -1;
}

itme_t dequeue(queue_t **Q)
{
    if(!is_empty_queue(Q))
    {
        int temp;
        temp=(*Q)->front;
       (*Q)->front=((*Q)->front+1)%(*Q)->size; 
       return (*Q)->base[temp];
    }
    return -1;
}

void remove_queue(queue_t **Q)
{
    free((*Q)->base);
    free(*Q);
}
/*******************************************************************************************/
#elif Q_IMPLEMENTATION == LINKLIST
/*******************************************************************************************/

typedef struct qq_t
{
    itme_t item;
    struct qq_t *next;
}qu_node_t;

typedef struct
{
   qu_node_t *insert;
   qu_node_t *remove;
}queue_t;


queue_t *queue_create()
{
   queue_t *Q=(queue_t*)calloc(1,sizeof(queue_t));
   
   Q->insert=Q->remove=NULL;
   
   return Q;
   
}

int is_empty_queue(queue_t **Q)
{
    
    return ((*Q)->insert == NULL);
}



void enqueue(queue_t **Q,itme_t x)
{
    qu_node_t * new_q=(qu_node_t*)calloc(1,sizeof(qu_node_t));
    new_q->item =x;
    new_q->next =NULL;
    if((*Q)->insert == NULL)
    {
        (*Q)->insert=(*Q)->remove=new_q;
    }
    else
    {
        (*Q)->remove->next=new_q;
        (*Q)->remove=new_q;
    }
}

itme_t dequeue(queue_t **Q)
{
    if(!is_empty_queue(Q))
    {
        qu_node_t *temp= (*Q)->insert;
        
        (*Q)->insert=(*Q)->insert->next;
        
        itme_t t = temp->item;
        
        free(temp);
        
        return t;
    
    }
    return -1;
}

void remove_queue(queue_t **Q)
{
   qu_node_t *temp= (*Q)->insert;
   
   while(temp !=NULL)
   {
       qu_node_t *temp1=temp;
       temp=temp->next;
       free(temp1);
   }
   (*Q)->insert=(*Q)->remove=NULL;
}
/*******************************************************************************************/
#elif Q_IMPLEMENTATION == CIRCULAR_LIST

typedef struct  qu_t
{
	itme_t item;
	struct  qu_t *next;
}

/*******************************************************************************************/
#else
/*******************************************************************************************/
/*******************************************************************************************/
#endif











