#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED


#include<stdbool.h>
struct Node
{
    int data;
    struct Node *next;


};
/**********************singly link list*************************************/
void displayList(struct Node **head_ptr);
int insertFisrt(struct Node **head_ptr,int data);
int insertLast(struct Node **head_ptr,int data);
int insertAt(struct Node **head_ptr,int data,int pos);

int deleteFisrt(struct Node **head_ptr);
int deleteLast(struct Node **head_ptr);
int deleteAt(struct Node **head_ptr,int pos);


int getMaxElement(struct Node **head_ptr);
int getMinElement(struct Node **head_ptr);

int isSortedList(struct Node **head_ptr);

int reverseList(struct Node **head_ptr);
int reverseListRecursive(struct Node **head_ptr,struct Node **curr_node,struct Node **prev_node);
int sortList(struct Node **head_ptr);

int removeDup(struct Node **head_ptr);

struct Node * linearSearch(struct Node **head_ptr,int key);


/*******************************singly link lis ****************************/

#endif // LINKLIST_H_INCLUDED
