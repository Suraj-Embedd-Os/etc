


#ifndef __STACK_H__
#define __STACK_H__

typedef struct SNode
{
	void * item;
	struct SNode *next;

}SNode_t;

typedef struct Stack
{
	struct SNode *sp;

}Stack_t;	

void stack_printInt(void *x);
void stack_printFloat(void *x);
void stack_printChar(void *x);

void * stack_Pop(Stack_t *s,size_t size);
int stack_Push(Stack_t *s,void * item,size_t size);
int stack_IsEmpty(Stack_t *s);
void stack_Display(Stack_t *s,void (*ptr)(void *));

#endif