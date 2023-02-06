
#include <stdio.h>
#include "queue.h"

struct Node *root=NULL;
void createTree( struct Queue **Q1_ptr);

void createTreeFromArray(struct Queue **Q1_ptr,int *arr,int num);
void inOrdeTraversal(struct Node *node);
void preOrderTraversal(struct Node *node);
void postOrderTraversal(struct Node *node);


int main()
{
    struct Queue *Q1=NULL;
   initialisedQueue(&Q1,50);
   
    createTree(&Q1);
    
    inOrdeTraversal(root);
    
    

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

void createTreeFromArray(struct Queue **Q1_ptr,int *arr,int num)
{
    
    struct Node *root =(struct Node *)malloc(1*sizeof(struct Node));
    
     struct Node *t=NULL,*p=NULL;
    
    root->data=arr[0];
    root->lchild=root->rchild=NULL;
    printf("root node %d \n",root->data);
    
    enQueue(Q1_ptr,root);
    
        while(!isEmptyQueue(Q1_ptr))
        {
             p=deQueue(Q1_ptr);
             
             printf("lchild of %d \n",p->data);
             
             if(arr[1])
        }
    

}

