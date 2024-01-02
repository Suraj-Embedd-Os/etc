

#ifndef __LIST_H__
#define __LIST_H__

typedef struct List
{
	void * item;
	struct List *next;

}List_t;	

void list_printInt(void *x);
void list_printFloat(void *x);
void list_printChar(void *x);

int list_InsertFirst(List_t **head,void * item,size_t size);
int list_InsertLast(List_t **head,void * item,size_t size);
int list_InsertAt(List_t **head,void * item,size_t size,unsigned char pos);

void list_Display(List_t *head,void (*prt)(void *));

#endif