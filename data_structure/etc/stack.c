
#include<stdio.h>
#include<stdlib.h>

#include"stack.h"



int push(struct Stack *s_ptr,char data)
{
    if(!isFull(s_ptr))
    {
        ++(s_ptr->top);
        s_ptr->data[s_ptr->top]=data;
    }
}

int pop(struct Stack *s_ptr)
{
    if(!isEmpty(s_ptr))
    {
         return s_ptr->data[(s_ptr->top)--];
    }
}

int peek(struct Stack *s_ptr)
{
    return s_ptr->data[(s_ptr->top)];
}

int isEmpty(struct Stack *s_ptr)
{
    return s_ptr->top==-1;
}

int isFull(struct Stack *s_ptr)
{
     return s_ptr->top==s_ptr->size-1;
}

void displayStack(struct Stack *s_ptr)
{
    if(!isEmpty(s_ptr))
    {
        for(int i=0;i<=s_ptr->top;i++)
        printf("%c ",s_ptr->data[i]);
    }
}


