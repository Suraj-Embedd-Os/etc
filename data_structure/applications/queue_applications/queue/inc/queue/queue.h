

#include "list/linkList.h"


struct Queue
{
	struct Node *Q;
};

int enQueue(struct Queue **q_ptr,int data);
int deQueue(struct Queue **q_ptr);

int isEmptyQ(struct Queue **q_ptr);

void displayQ(struct Queue **q_ptr);