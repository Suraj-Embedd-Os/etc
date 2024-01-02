
#include<stdio.h>
#include<stdlib.h>
#include"list.h"


void list_printInt(void *x)
{ 
     printf("%d ", *(int *)x );
}

void list_printChar(void *x)
{ 
     printf("%c ", *(char *)x );
}

void list_printFloat(void *x)
{ 
     printf("%f ", *(float *)x );
}



int list_InsertFirst(List_t **head,void * item,size_t size)
{
	List_t *new_node=(List_t*)calloc(1,sizeof(List_t));
	
	new_node->item=calloc(1,size);
	
	for(int i=0;i<size;i++)
	{
	    *(char*)(new_node->item + i)=*(char*)(item+i);
	}
	
	new_node->next=*head;
	*head=new_node;

	return 0;
	
		
}

int list_InsertLast(List_t **head,void * item,size_t size)
{
	List_t *new_node=(List_t*)calloc(1,sizeof(List_t));
	
	new_node->item=calloc(1,size);
	
	for(int i=0;i<size;i++)
	{
	    *(char*)(new_node->item + i)=*(char*)(item+i);
	}
	
	if(*head == NULL)
	{
		new_node->next=*head;
		*head=new_node;
		
	}
	else
	{
		List_t *temp=*head;
		
		while(temp->next!=NULL)
			temp=temp->next;
		
		temp->next=new_node;
	}
	
	

	return 0;
}

int list_InsertAt(List_t **head,void * item,size_t size,unsigned char pos)
{
	List_t *new_node=(List_t*)calloc(1,sizeof(List_t));
	
	new_node->item=calloc(1,size);
	
	for(int i=0;i<size;i++)
	{
	    *(char*)(new_node->item + i)=*(char*)(item+i);
	}
	
	List_t * temp=*head;
	for(int i=1;i<=pos ;i++)
	{
		
		if(pos == 1)
		{
			new_node->next=*head;
			*head=new_node;
		}
		else
		{
			List_t * prev=temp;
			
			if(prev==NULL)
			{
				printf("Not valid index \n");
				return 1;
			}
			if(prev && i==pos-1)
			{
				new_node->next=prev->next;
				prev->next=new_node;
				return 0;
			}
			
			temp=temp->next;
			
		}
	}
	
	return 0;
	
	
}

void list_Display(List_t *head,void (*prt)(void *))
{
	
	while(head)
	{
	    (*prt)(head->item);
	    head=head->next;
	}
	printf("\n");
}



