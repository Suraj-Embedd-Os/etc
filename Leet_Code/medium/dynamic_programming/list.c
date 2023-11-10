
#include <stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node * next;
    int data;
    
};


int insertLast(struct Node **head_ptr,int data);
int displayList(struct Node **head_ptr);
int createList(struct Node **head_ptr,int *arr,int arrSize);
int deleteNodeFormLast(struct Node **head_ptr,int kth);

struct Node * mergeList(struct Node **head_l1,struct Node **head_l2);

int main()
{
  struct Node *head=NULL,*head2=NULL;
  
  int arr[9]={1,2,3,4,5,6,7,8,9};
  int arr2[8]={10,20,30,40,50,60,70,80};
  createList(&head,arr,9);
  createList(&head2,arr2,8);
  
  struct Node *new_list=mergeList(&head,&head2);
  
  displayList(&head);
  displayList(&head2);
  displayList(&new_list);
  

  
    
    return 0;
}



int insertLast(struct Node **head_ptr,int data)
{
    struct Node *new_node=(struct Node *)malloc(1*sizeof(struct Node ));
    if(new_node==NULL)
    {
       printf("unable to allocate head memory %s %d",__FILE__,__LINE__);
       exit(-1);
    }

    new_node->data=data;
    new_node->next=NULL;

    if(*head_ptr==NULL)
    {
        *head_ptr=new_node;
        return 0;
    }

    struct Node *temp=*head_ptr;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=new_node;
	
	return 0;
}

int displayList(struct Node **head_ptr)
{
    struct Node *temp=*head_ptr;

    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
    return 0;
}

int createList(struct Node **head_ptr,int *arr,int arrSize)
{
    for(int i=0;i<arrSize;i++)
    insertLast(head_ptr,arr[i]);
    
    return 0;
}

int deleteNodeFormLast(struct Node **head_ptr,int kth)
{
    struct Node * slow=*head_ptr;
    struct Node * fast=*head_ptr;
    
    while(kth>0)
    {
        fast=fast->next;
        kth--;
    }
    
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
        
    }
     struct Node * temp=slow->next;
     slow->next=slow->next->next;
     
     free(temp);
}

struct Node * mergeList(struct Node **head_l1,struct Node **head_l2)
{
     static struct Node * new_list=NULL;
     static struct Node * l1=NULL;
     l1=*head_l1;
     struct Node * l2=*head_l2;
    
    if(l2==NULL || l1==NULL)
    return NULL;
    else
    {
      
            
        mergeList(&l1,&l2->next);
        insertLast(&new_list,l1->data);
        l1=l1->next;
        insertLast(&new_list,l2->data);
           
    }
    

    
 
    return new_list;
}
