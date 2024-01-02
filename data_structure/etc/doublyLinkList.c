
#include<stdio.h>
#include<stdlib.h>
#include"doublyLinkList.h"


int D_insertFirst(struct Node **head_ptr,int data)
{
    struct Node *new_node=(struct Node *)malloc(1*sizeof(struct Node ));
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=NULL;
    
    if(*head_ptr==NULL)
    {
        *head_ptr=new_node;
        return 0;
    }
    else
    {
     
     new_node->next=*head_ptr;
     (*head_ptr)->prev=new_node;
     *head_ptr=new_node;
    }
    return 0;
}

int D_insertLast(struct Node **head_ptr,int data)
{
    struct Node *new_node=(struct Node *)malloc(1*sizeof(struct Node ));
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=NULL;
    
    if(*head_ptr==NULL)
    {
        *head_ptr=new_node;
        return 0;
    }
    else
    {
        struct Node *curr_node=*head_ptr;
     
        while(curr_node->next!=NULL)
        curr_node=curr_node->next;

            
        curr_node->next=new_node;
        new_node->prev=curr_node;
        
    }
}

int D_insertAt(struct Node **head_ptr,int data,int pos)
{
    struct Node *new_node=(struct Node *)malloc(1*sizeof(struct Node ));
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=NULL;
     struct Node *curr_node=*head_ptr;
      struct Node *prev_node=NULL;
     
    for(int i=0;i<pos;i++)
    {
        if(i==0 && pos==1)
        {
            new_node->next=*head_ptr;
            (*head_ptr)->prev=new_node;
            *head_ptr=new_node;
            return 0;
        }
        else
        {
            if(i==pos-1 && curr_node)
            {
                prev_node->next=new_node;
                new_node->prev=prev_node;
                new_node->next=curr_node;
                curr_node->prev=new_node;
                return 0;
            }
            prev_node=curr_node;
            curr_node=curr_node->next;
            
            if(curr_node==NULL)
            {
                printf("out of index \n");
                return 0;
            }
        }
    }
}

int D_deleteFirst(struct Node **head_ptr)
{
    int data=(*head_ptr)->data;
    
    struct Node *curr_node=*head_ptr;
    
    *head_ptr=(*head_ptr)->next;
    
    curr_node->next->prev=NULL;
    
    free(curr_node);
    
}

int D_deleteLast(struct Node **head_ptr)
{
   int data;
    
    struct Node *curr_node=*head_ptr;
    
    while(curr_node->next!=NULL)
    {
        curr_node=curr_node->next;
    }
    
      data=curr_node->data;
    curr_node->prev->next=NULL;
    
    free(curr_node); 
    
    return data;
}

int D_deleteAt(struct Node **head_ptr,int pos)
{
    int data=-1;
    struct Node *curr_node=*head_ptr;
    for(int i=0;i<pos;i++)
    {
        if(i==0 && pos==1)
        {
            D_deleteFirst(head_ptr);
            return 0;
        }
        else
        {
            if(i==pos-1 && curr_node)
            {
                curr_node->prev->next=curr_node->next;
                data=curr_node->data;
                free(curr_node);
                return data;
            }
            
            curr_node=curr_node->next;
            
            if(curr_node==NULL)
            {
                printf("out of index\n");
                return -1;
            }
        }
    }
}

void D_display(struct Node **head_ptr)
{
    struct Node *temp=*head_ptr;
    
    while(temp !=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


