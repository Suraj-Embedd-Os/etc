#ifndef __CIRCULAR_LIST_
#define __CIRCULAR_LIST_

struct Node
{
    int data;
    struct Node *next;
};

void cir_didplay(struct Node **head_ptr);

int cir_insertFirst( struct Node **head_ptr,int data);
int cir_insertLast( struct Node **head_ptr,int data);
int cir_insertAt( struct Node **head_ptr,int data,int pos);

int cir_deleteFirst( struct Node **head_ptr);
int cir_deleteLast( struct Node **head_ptr);
int cir_deleteAt( struct Node **head_ptr,int pos);

struct Node *cir_mergeList( struct Node **firstHead,struct Node **secondHead);



#endif
