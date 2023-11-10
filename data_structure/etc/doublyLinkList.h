

#ifndef __DOUBLY_
#define __DOUBLY_

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

int D_insertFirst(struct Node **head_ptr,int data);
int D_insertLast(struct Node **head_ptr,int data);
int D_insertAt(struct Node **head_ptr,int data,int pos);

int D_deleteFirst(struct Node **head_ptr);
int D_deleteLast(struct Node **head_ptr);
int D_deleteAt(struct Node **head_ptr,int pos);

void D_display(struct Node **head_ptr);


#endif

