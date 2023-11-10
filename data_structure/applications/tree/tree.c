
#include <stdio.h>
#include<limits.h>
#include "queue.h"

struct Node *root=NULL;
void createTree( struct Queue **Q1_ptr);


void createTreeFromArray(int *arr,int num);
void inOrdeTraversal(struct Node *node);
void preOrderTraversal(struct Node *node);
void postOrderTraversal(struct Node *node);

int sumofAllNode(struct Node *node);
int maxElementInTree(struct Node *node);
int minElementInTree(struct Node *node);
int noOfNodeInTree(struct Node *node);


int max(int a,int b)
{
    return (a>b?a:b);
}
int min(int a,int b)
{
    return (a<b?a:b);
}


int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    //struct Queue *Q1=NULL;
   // initialisedQueue(&Q1,50);
   createTreeFromArray(arr,sizeof(arr)/sizeof(int));
    //createTree(&Q1);
    
    preOrderTraversal(root);
    
    printf("\n%d ",sumofAllNode(root));
    
    printf("\n%d ",noOfNodeInTree(root));
    
    

    return 0;
}

void preOrderTraversal(struct Node *node)
{
     if(node==NULL)
    return;
    printf("%d ",node->data);
    preOrderTraversal(node->lchild);
    preOrderTraversal(node->rchild);
}
void postOrderTraversal(struct Node *node)
{
     if(node==NULL)
    return;
    postOrderTraversal(node->lchild);
    postOrderTraversal(node->rchild);
    printf("%d ",node->data);
}

void inOrdeTraversal(struct Node *node)
{
    if(node==NULL)
    return;
    inOrdeTraversal(node->lchild);
    printf("%d ",node->data);
    inOrdeTraversal(node->rchild);
}

void createTree( struct Queue **Q1_ptr)
{
    struct Node *t=NULL,*p=NULL;
    int data;
    printf("Enter root node data \n");
    scanf("%d",&data);
    
    root=(struct Node *)malloc(1*sizeof(struct Node ));
    root->data=data;
    root->lchild=NULL;
    root->rchild=NULL;
    
    enQueue(Q1_ptr,root);
    
    while(!isEmptyQueue(Q1_ptr))
    {
        p=deQueue(Q1_ptr);
        
        printf("Enter lchild of %d \n",p->data);
        scanf("%d",&data);
        if(data!=-1)
        {
            t=(struct Node *)malloc(1*sizeof(struct Node ));
            t->data=data;
            t->lchild=NULL;
            t->rchild=NULL;
            p->lchild=t;
            enQueue(Q1_ptr,t);
        }
        
        printf("Enter rchild of %d \n",p->data);
        scanf("%d",&data);
        if(data!=-1)
        {
            t=(struct Node *)malloc(1*sizeof(struct Node ));
            t->data=data;
            t->lchild=NULL;
            t->rchild=NULL;
             p->rchild=t;
            enQueue(Q1_ptr,t);
        }
        
        
    }
    
   
}

void createTreeFromArray(int *arr,int num)
{
    
    root =(struct Node *)malloc(1*sizeof(struct Node));
    
    struct Node *t=NULL,*p=NULL;
    
    root->data=arr[0];
    root->lchild=root->rchild=NULL;
    printf("root node %d \n",root->data);
    
	for(int i=1;i<num;i++)
	{
		struct Node *temp=root;
		struct Node *prev=NULL;
		
		struct Node *new_node=(struct Node*)malloc(1*sizeof(struct Node));
		new_node->data=arr[i];
		new_node->lchild=new_node->rchild=NULL;
		
		
		while(temp!=NULL)
		{
			prev=temp;
			if(temp->data >arr[i])
				temp=temp->lchild;
			else
				temp=temp->rchild;
				
			
		}
		
		if(prev->data>arr[i])
			prev->lchild=new_node;
		else
			prev->rchild=new_node;
		
	}
    
    
}

int sumofAllNode(struct Node *node)
{
   if(node==NULL)
   return 0;
   else
   return (node->data +sumofAllNode(node->lchild)+sumofAllNode(node->rchild));
}

int maxElementInTree(struct Node *node)
{
    if(node==NULL)
    return INT_MIN;
    else
    return max(node->data,max(maxElementInTree(node->lchild),maxElementInTree(node->rchild)));
}

int minElementInTree(struct Node *node)
{
     if(node==NULL)
    return INT_MAX;
    else
    return min(node->data,min(minElementInTree(node->lchild),minElementInTree(node->rchild)));
}

int noOfNodeInTree(struct Node *node)
{
    if(node==NULL)
    return 0;
    return 1+noOfNodeInTree(node->lchild)+noOfNodeInTree(node->rchild);
    
}
