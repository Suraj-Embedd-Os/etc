/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertLast(struct Node **nodePtr,int data)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;
    
    if((*nodePtr)==NULL)
    {
        *nodePtr=new_node;
        return;
    }
    
    struct Node *temp=*nodePtr;
    
    while(temp->next!=NULL)
    temp=temp->next;
    
    temp->next=new_node;
}


void display(struct Node *nodePtr)
{
    
    while(nodePtr!=NULL)
    {
        printf("%d ",nodePtr->data);
        nodePtr=nodePtr->next;
    }
    printf("\n");
}

void deletePos(struct Node **nodePtr,int pos)
{
    
    struct Node *temp=*nodePtr;
     struct Node *prev=*nodePtr;
    int i=0;
    
    if(*nodePtr!=NULL)
    {
        
        for(i=0;i<pos;i++)
        {
            if(i==0 && pos==1 )
            {
                *nodePtr=(*nodePtr)->next;
                free(temp);
            }
            else
            {
               if(i==pos-1 && temp) 
               {
                   prev->next=temp->next;
                   free(temp);
               }
               else
               {
                   prev=temp;
                   
                   if(prev==NULL)
                   {
                       printf("position is greater than no of node\n");
                       break;
                   }
                   temp=temp->next;
                   
               }
            }
            
        }
    }
}

void insetAt(struct Node **nodePtr,int data,int pos)
{
    
    struct Node *temp=*nodePtr;
     struct Node *prev=*nodePtr;
     
     
     struct Node *new_node=(struct Node *)malloc(sizeof(struct Node ));
     
     new_node->data=data;
     new_node->next=NULL;
     
    int i=0;
    
       
        for(i=0;i<pos;i++)
        {
            if(i==0 && pos==1 )
            {
                new_node->next=*nodePtr;
                *nodePtr=new_node;
                
            }
            else
            {
               if(i==pos-1 && temp) 
               {
                    new_node->next=temp;
                    prev->next=new_node;
                   
               }
               else
               {
                   prev=temp;
                   
                   if(prev==NULL)
                   {
                       printf("position is greater than no of node\n");
                       break;
                   }
                   temp=temp->next;
                   
               }
            }
            
        }
    
}



int main()
{
   
   int arr[5]={5,3,4,7,8};
   int i;
   struct Node *head=NULL;
   
   for(i=0;i<5;i++)
   {
       insertLast(&head,arr[i]);
   
   }
   
   display(head);
   insetAt(&head,50,6);
   display(head);

    return 0;
}



