#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void push(Node **headRef,int data)
{
    Node *new_node =new Node();
    
    new_node->data=data;
    new_node->next=*headRef;
    
    *headRef=new_node;
}

void append(Node **headRef,int data)
{
    Node *new_node =new Node();
    new_node->data=data;
    new_node->next=NULL;
    
    if(*headRef==NULL)
    {
        *headRef=new_node;
    }
    
    Node *temp=*headRef;
    
    while(temp->next!=NULL)
    temp=temp->next;
    
    temp->next=new_node;
    
}

void afterNode(Node *node,int data)
{
    if(node==NULL)
    {
        cout<<"The given previous node cannot be NULL";
        return;
    }
    
    Node *new_node =new Node();
    new_node->data=data;
    new_node->next=node->next;
    
    node->next=new_node;
    
    
    
}

void display(Node *ptr)
{
    while(ptr)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main()
{
    Node *head=NULL;
    
    push(&head,1);
    append(&head,2);
    append(&head,5);
    afterNode(head->next,3);
    
    display(head);
    return 0;
}
