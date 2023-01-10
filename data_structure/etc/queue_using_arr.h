

#ifndef __QUEUE_
#define __QUEUE_


struct Queue
{
	int *Q;
	int size;
	int rear;
	int front;
	
};

int initialisedQueue(struct Queue **Q_ptr,int length);
int enqueue(struct Queue **Q_ptr,int data);
int dequeue(struct Queue **Q_ptr);


int isEmptyQueue(struct Queue **Q_ptr);
int isFullQueue(struct Queue **Q_ptr);
void displayQueue(struct Queue **Q_ptr);




#endif
