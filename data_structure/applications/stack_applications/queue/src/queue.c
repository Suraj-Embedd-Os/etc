
#include<stdio.h>
#include<stdlib.h>

#include"list/linkList.h"
#include"queue/queue.h"

int enQueue(struct Queue **q_ptr,int data)
{
	return insertFisrt(&(*q_ptr)->Q,data);
	
}

int deQueue(struct Queue **q_ptr)
{
	int _data=deleteLast(&(*q_ptr)->Q);
	return _data; 
}

int isEmptyQ(struct Queue **q_ptr)
{
	return (*q_ptr)->Q==NULL;
}

void displayQ(struct Queue **q_ptr)
{
	struct Node *temp=(*q_ptr)->Q;
	
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

