#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED



#include"list/linkList.h"

struct stack
{
   struct Node *top;

};

int push(struct stack **st_ptr,int data);
int pop(struct stack **st_ptr);
int peek(struct stack **st_ptr);
int isEmpty(struct stack **st_ptr);
void displayStack(struct stack **st_ptr);

#endif // STACK_H_INCLUDED
