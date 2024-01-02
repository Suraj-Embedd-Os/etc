/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void createList(int *arr,int num)
{
    for(int i=0;i<num;i++)
    {
        struct Node *temp=(struct Node*)malloc(1*sizeof(struct Node));
        temp->next=NULL;
        temp->data=arr[i];
        
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            struct Node *temp1=head;
            
            while(temp1->next!=NULL)
            temp1=temp1->next;
            
            temp1->next=temp;
        }
    }
}

void display()
{
    struct Node *temp1=head;
     
    while(temp1)
    {
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
        printf("\n");
}

void swapAdjucent()
{
    if(head==NULL || head->next==NULL)
    return;
    
   struct Node *dummy=(struct Node *)malloc(1*sizeof(struct Node ));
   
   dummy->next=head;
   
   struct Node *currNode=head;
   struct Node *prevNode=dummy;
   
   while(currNode && currNode->next != NULL)
   {
       prevNode->next=currNode->next;
       currNode->next=prevNode->next->next;
       prevNode->next->next=currNode;
       
       prevNode=currNode;
       currNode=currNode->next;
   }
   
   head=dummy->next;
   
   free(dummy);
    
}

int main()
{
    
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    
    createList(a,9);
    
    display();
    swapAdjucent();
     display();
    
    
    return 0;
}



