

#ifndef _STACK_H
#define  _STACK_H

#include<stdio.h>
#include<stdlib.h>

#include "queue.h"



struct Stack{
	
	struct Node **data;
	int size;
	int top;
	
};

int intialisedStack(struct Stack **stk_ptr,int size)
{
	struct Stack *st=(struct Stack*)malloc(1*sizeof(struct Stack));
	st->size=size;
	st->top=-1;
	
	st->data=(struct Node **)malloc(size*sizeof(struct Node ));
	
	*stk_ptr=st;
	
	return 0;
	
	
}

int isFull(struct Stack **stk_ptr)
{
	return ((*stk_ptr)->top==(*stk_ptr)->size-1);
}

int isEmpty(struct Stack **stk_ptr)
{
	return ((*stk_ptr)->top==-1);
}

struct Stack * peek(struct Stack **stk_ptr)
{
	return (*stk_ptr)->data[(*stk_ptr)->top];
}

int push(struct Stack **stk_ptr,int data)
{
	if(!isFull(stk_ptr))
	{
		(*stk_ptr)->top++;
		(*stk_ptr)->data[(*stk_ptr)->top]=data;
		return 0;
	}
	printf("Stack full %d %s ",__LINE__,__FILE__);
	return -1;
}

struct Stack * pop(struct Stack **stk_ptr)
{
	if(!isEmpty(stk_ptr))
	{
		(*stk_ptr)->top--;
		
		return (*stk_ptr)->data[(*stk_ptr)->top];
	}
	printf("Stack empty %d %s ",__LINE__,__FILE__);
	return -1;
}

int displaStackData(struct Stack **stk_ptr)
{
	if(isEmpty(stk_ptr))
	{
	    printf("Stack empty %d %s ",__LINE__,__FILE__);
		return -1;
		
	}
	
	int i=(*stk_ptr)->top;
	for(;i>=0;i--)
	{
		printf("%d ",(*stk_ptr)->data[i]);
	}
	printf("\n");
}




#endif