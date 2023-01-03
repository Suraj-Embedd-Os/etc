
#include<stdio.h>
#include<stdlib.h>
#include"circularList.h"

int insertCFisrt(struct Node **head_ptr,int data)
{
    struct Node *new_node=(struct Node *)malloc(1*sizeof(struct Node ));

    if(new_node==NULL)
    {
        printf("unable to create node %d %s",__LINE__,__FILE__);
        return -1;
    }
    new_node->data=data;
    if(*head_ptr==NULL)
    {
        *head_ptr=new_node;
        new_node->next=*head_ptr;
        return 0;
    }
    else if((*head_ptr)->next==*head_ptr)
    {
        new_node->next=*head_ptr;
        (*head_ptr)->next=new_node;
        *head_ptr=new_node;
        return 0;
    }

    struct Node *temp=*head_ptr;
    do
    {
    temp=temp->next;
    }while(temp->next!=*head_ptr);

    new_node->next=*head_ptr;
    *head_ptr=new_node;
    temp->next=*head_ptr;

    return 0;
}

int displayCirularList(struct Node **head_ptr)
{

    struct Node *temp=*head_ptr;
    if(*head_ptr!=NULL)
    {
           do
            {
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=*head_ptr);

        printf("\n");
    }



    return 0;
}


