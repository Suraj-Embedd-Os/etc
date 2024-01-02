


#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct QNode
{
	void * item;
	struct QNode *next;

}QNode_t;


typedef struct Queue
{
	struct QNode *rear;
	struct QNode *front;

}Queue_t;	

void queue_printInt(void *x);
void queue_printFloat(void *x);
void queue_printChar(void *x);

int queue_Enqueue(Queue_t *q,void *item,size_t size);
int queue_Dequeue(Queue_t *q,size_t size);

void queue_Display(Queue_t *q,void (*ptr)(void *));

#endif