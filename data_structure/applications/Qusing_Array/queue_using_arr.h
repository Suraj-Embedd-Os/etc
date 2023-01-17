

#ifndef __QUEUE_USING_ARR_
#define __QUEUE_USING_ARR_

struct Queue
{
	int *data;
	int length;
	int front;
	int rear;
	
};

int initialisedQueue(struct Queue **Q_ptr,int length);
int isEmptyQueue(struct Queue **Q_ptr);
int isFullQueue(struct Queue **Q_ptr);

int enQueue(struct Queue **Q_ptr,int data);
int deQueue(struct Queue **Q_ptr);

int displayQueue(struct Queue **Q_ptr);

#endif
