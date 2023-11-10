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
void insertFisrt(struct Node **head_ptr,int data);
void insertLast(struct Node **head_ptr,int data);
void insertAt(struct Node **head_ptr,int data,int pos);

void deleteFisrt(struct Node **head_ptr);
void deleteLast(struct Node **head_ptr);
void deleteAt(struct Node **head_ptr,int pos);


int getMaxElement(struct Node **head_ptr);
int getMinElement(struct Node **head_ptr);

bool isSortedList(struct Node **head_ptr);

void reverseList(struct Node **head_ptr);
void reverseListRecursive(struct Node **head_ptr,struct Node **curr_node,struct Node **prev_node);
void sortList(struct Node **head_ptr);

void removeDup(struct Node **head_ptr);

struct Node * linearSearch(struct Node **head_ptr,int key);


/*******************************singly link lis ****************************/

#endif // LINKLIST_H_INCLUDED
