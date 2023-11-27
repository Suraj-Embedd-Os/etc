
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"


void stack_printInt(void *x)
{
	printf("%d ", *(int *)x );
}

void stack_printFloat(void *x)
{
	printf("%f ", *(float *)x );
}

void stack_printChar(void *x)
{
	
	printf("%c ", *(char *)x );
}

void * stack_Pop(Stack_t *s,size_t size)
{
    if(stack_IsEmpty(s))
    {
        
        printf("Stack is empty\n");
        return NULL;
    }
    
	void * item;
	item = calloc(1,size);
	
	for(int i=0;i<size;i++)
	*(char*)(item+i)=*(char*)(s->sp->item+i);
	
	SNode_t *temp = s->sp;
	s->sp=s->sp->next;
	
	free(temp);
	
	return item;
}

int stack_Push(Stack_t *s,void * item,size_t size)
{
	
	SNode_t * new_node = (SNode_t*)calloc(1,sizeof(SNode_t));
		
	new_node->item=calloc(1,size);
	
	
	for(int i=0;i<size;i++)
	{
		*(char*)(new_node->item+i)= *(char*)(item + i);
	}
	new_node->next=s->sp;
	s->sp=new_node;
	return 0;
}

int stack_IsEmpty(Stack_t *s)
{
    return s->sp==NULL;
}

void stack_Display(Stack_t *s,void (*ptr)(void *))
{
	SNode_t *l=s->sp;
	while(l)
	{
		(*ptr)(l->item);
		l=l->next;
	}
	printf("\n");
}