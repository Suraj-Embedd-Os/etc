

#ifndef __LINK_LIST_H
#define __LINK_LIST_H

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *next;
    int data;
    
};

void createList(struct Node **head_ptr,int *arr,int n);
void inserLast(struct Node **head_ptr,int data);
void insertFirst(struct Node **head_ptr,int data);
int deleteFirst(struct Node **head_ptr);
int deleteLast(struct Node **head_ptr);

void displayList(struct Node *head_ptr)
{
    struct Node *temp=head_ptr;
    
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void inserLast(struct Node **head_ptr,int data)
{
    struct Node *new_node=(struct Node*)malloc(1*sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;
    
    if(*head_ptr==NULL)
    {
        *head_ptr=new_node;
        return;
    }
     struct Node *temp=*head_ptr;
     
     while(temp->next!=NULL)
      temp=temp->next;
      temp->next=new_node;
      
}

void createList(struct Node **head_ptr,int *arr,int n)
{	
	
	for(int i=0;i<n;i++)
	{
	    inserLast(head_ptr,arr[i]);
	}
}

void insertFirst(struct Node **head_ptr,int data)
{
    struct Node *new_node=(struct Node*)malloc(1*sizeof(struct Node));
    new_node->data=data;
    new_node->next=*head_ptr;
     *head_ptr=new_node;
   
}


int deleteFirst(struct Node **head_ptr)
{
   int data;
     data=(int)(*head_ptr)->next;
   struct Node *temp=*head_ptr;
   *head_ptr=(*head_ptr)->next; 
   
   free(temp);
   
   return data;
}
int deleteLast(struct Node **head_ptr)
{
    int data;
   
   
   struct Node *temp=*head_ptr;
   struct Node *prev=NULL;
     
     while(temp->next!=NULL){
         prev=temp;
        temp=temp->next;
   
     }
     prev->next=NULL;
     data=temp->data;
     
   free(temp);
   
   return data;
}
#endif