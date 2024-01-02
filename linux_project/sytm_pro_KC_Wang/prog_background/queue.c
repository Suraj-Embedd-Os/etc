#include<string.h>
#include <stdio.h>
#include<stdlib.h>

typedef struct entry
{
    struct entry * next;
    char name[64];
    int priority;
}ENTRY;

void printQ(ENTRY * q)
{
    
    while(q)
    {
        printf("[%s %d]-> ",q->name,q->priority);
        q=q->next;
    }
    printf("\n");
}

void enqueue(ENTRY ** queue  ,ENTRY *p)
{
    ENTRY *q=*queue;
    printQ(q);
    
    if(q==0 || q->priority<p->priority)
    {
        *queue=p;
        p->next=q;
    }
   else{ // not first in queue; insert to the right spot
        while (q->next && p->priority <= q->priority)
        q = q->next;
        p->next = q->next;
        q->next = p;
        }
        printQ(q); // show queue after insertion
}

ENTRY *Q;

int main()
{
  
    ENTRY *q[5];
    
    char *name[]={"hello","hii","hilllo","hee","zee"};
    for(int i=0;i<5 ;i++)
    {
        q[i]=(ENTRY*)calloc(1,sizeof(ENTRY));
        strcpy(q[i]->name,name[i]);
        q[i]->priority = i+1;
        enqueue(&Q,q[i]);
    }
    
    return 0;
}
