
#include<stdio.h>
#include<stdlib.h>

#include"circularList.h"

void cir_didplay(struct Node **head_ptr)
{
    if(*head_ptr!=NULL)
    {
        struct Node *temp=*head_ptr;
        
        do
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=*head_ptr);
        
        printf("\n");
    }
    
}

int cir_insertFirst( struct Node **head_ptr,int data)
{
    struct Node *new_node =(struct Node *)malloc(1*sizeof(struct Node ));
    new_node->data=data;

    new_node->next=*head_ptr;
    
    if(*head_ptr!=NULL)
    {
        struct Node *temp=*head_ptr;
        
        while(temp->next!=*head_ptr)
        temp=temp->next;
        
        temp->next=new_node;
        *head_ptr=new_node;
    }
    else
    {
        new_node->next=new_node;
        *head_ptr=new_node;
    }
       
       
    return 0;
   
}

int cir_insertLast( struct Node **head_ptr,int data)
{
    struct Node *new_node =(struct Node *)malloc(1*sizeof(struct Node ));
    new_node->data=data;

    
    if(*head_ptr!=NULL)
    {
        struct Node *temp=*head_ptr;
        
        while(temp->next!=*head_ptr)
        temp=temp->next;
        
        temp->next=new_node;
        new_node->next=*head_ptr;
    }
    else
    {
        new_node->next=new_node;
        *head_ptr=new_node;
    }
       
       
    return 0;
}

int cir_insertAt( struct Node **head_ptr,int data,int pos)
{
    if(*head_ptr!=NULL)
    {
        struct  Node *new_node=(struct  Node *)malloc(1*sizeof(struct  Node ));
        new_node->data=data;
         struct Node *curr_node=*head_ptr,*prev_node=NULL;
        for(int i=0;i<pos;i++)
        {
            if(i==0 && pos==1)
            {
                new_node->next=*head_ptr;
                curr_node=*head_ptr;
                
                while(curr_node->next!=*head_ptr)
                curr_node=curr_node->next;
                
                curr_node->next=new_node;
                 *head_ptr=new_node;
            }
            else
            {
                if(i==pos-1 && curr_node!=*head_ptr)
                {
                    prev_node->next=new_node;
                    new_node->next=curr_node;
                    return 0;
                }
                prev_node=curr_node;
                curr_node=curr_node->next;
                
                if(curr_node==*head_ptr)
                {
                    printf("out of index ");
                    return -1;
                }
            }
        }
    }
    return 0;
}

int cir_deleteFirst( struct Node **head_ptr)
{
    if(*head_ptr!=NULL)
    {
        int data=(*head_ptr)->data;
        struct Node *temp=*head_ptr;
         struct Node *temp1=*head_ptr;
         
         if((*head_ptr)->next==*head_ptr)
         {
             free(*head_ptr);
             *head_ptr=NULL;
             
         }
         else
         {
         
             while(temp1->next!=*head_ptr)
             temp1=temp1->next;
             
             temp1->next=(*head_ptr)->next;
             
             *head_ptr=(*head_ptr)->next;
             
             free(temp);
         }
     return data;
    }
    
    
}

int cir_deleteLast( struct Node **head_ptr)
{
    if(*head_ptr!=NULL)
    {
        int data=(*head_ptr)->data;
        struct Node *curr_node=*head_ptr;
         struct Node *prev_node=NULL;
         
         if((*head_ptr)->next==*head_ptr)
         {
             free(*head_ptr);
             *head_ptr=NULL;
             
         }
         else
         {
         
             while(curr_node->next!=*head_ptr)
             {
                 prev_node=curr_node;
                 curr_node=curr_node->next;
             }
             
             prev_node->next=curr_node->next;
             
             free(curr_node);
         }
     return data;
    }
}

int cir_deleteAt( struct Node **head_ptr,int pos)
{
    if(*head_ptr!=NULL)
    {
         struct Node *curr_node=*head_ptr,*prev_node=NULL;
        for(int i=0;i<pos;i++)
        {
            if(i==0 && pos==1)
            {
                if((*head_ptr)->next==*head_ptr)
                {
                    free(*head_ptr);
                    *head_ptr=NULL;
                }
                else
                {
                  
                    while(curr_node->next!=*head_ptr)
                    curr_node=curr_node->next;
                    
                    prev_node=*head_ptr;
                    curr_node->next=(*head_ptr)->next;
                     *head_ptr=(*head_ptr)->next;
                     
                     free(prev_node);
                }
            }
            else
            {
                if(i==pos-1 && curr_node!=*head_ptr)
                {
                    prev_node->next=curr_node->next;
                  free(curr_node);
                    return 0;
                }
                prev_node=curr_node;
                curr_node=curr_node->next;
                
                if(curr_node==*head_ptr)
                {
                    printf("out of index ");
                    return -1;
                }
            }
        }
    }
    return 0;
}





struct Node *cir_mergeList( struct Node **firstHead,struct Node **secondHead)
{
    struct Node *new_list=( struct Node *)malloc(1*sizeof( struct Node ));
    
    struct Node * first_list=*firstHead;
    struct Node * second_list=*secondHead;
    
    while(first_list->next!=*firstHead  || second_list->next!=*secondHead)
    {
        if(first_list->data <second_list->data)
        {
            cir_insertLast(&new_list,first_list->data);
            first_list=first_list->next;
        }
        else
        {
             cir_insertLast(&new_list,second_list->data);
            second_list=second_list->next;
        }
    }
    
      while(first_list->next!=*firstHead )
       {
          cir_insertLast(&new_list,first_list->data);
            first_list=first_list->next;
       }
       while(second_list->next!=*secondHead)
       {
           cir_insertLast(&new_list,second_list->data);
            second_list=second_list->next;
       }
    return new_list;
}


