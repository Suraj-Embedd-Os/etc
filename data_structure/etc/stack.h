
#ifndef __STACK_H
#define __STACK_H


struct Stack
{
    char *data;
    int top;
    int size;
};

int push(struct Stack *s_ptr,char data);
int pop(struct Stack *s_ptr);
int peek(struct Stack *s_ptr);
int isEmpty(struct Stack *s_ptr);
int isFull(struct Stack *s_ptr);

void displayStack(struct Stack *s_ptr);






#endif