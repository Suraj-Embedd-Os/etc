
#include<stdio.h>
#include<stdlib.h>
#include"stack/stack.h"
#include"list/linkList.h"




int push(struct stack **st_ptr,int data)
{
    insertFisrt(&(*st_ptr)->top,data);
    return 0;
}

int pop(struct stack **st_ptr)
{
    int _data=deleteFisrt(&(*st_ptr)->top);
    return _data;
}

int peek(struct stack **st_ptr)
{
	return (((*st_ptr)->top)->data);
	
}
int isEmpty(struct stack **st_ptr)
{
	return (*st_ptr)->top==NULL;
}

void displayStack(struct stack **st_ptr)
{
    struct Node *temp=(*st_ptr)->top;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
