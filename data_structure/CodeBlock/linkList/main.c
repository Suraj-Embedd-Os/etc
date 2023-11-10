#include <stdio.h>
#include <stdlib.h>
#include"linkList.h"

int main()
{
    /*struct Node *head=NULL;
    insertLast(&head,100);
    insertLast(&head,100);
    insertLast(&head,100);
    insertLast(&head,100);
    insertLast(&head,100);
    insertLast(&head,100);
    insertLast(&head,100);
    insertLast(&head,100);
    /*insertAt(&head,180,3);
    insertAt(&head,180,4);
    insertAt(&head,180,5);*/
    //displayList(&head);
    //reverseList(&head);
    //reverseListRecursive(&head,&(head->next),&head);
    //deleteFisrt(&head);
    //deleteLast(&head);
    //deleteAt(&head,4);
   // removeDup(&head);
   // displayList(&head);

    //printf("%d ",isSortedList(&head));

    struct Node *head_circular=NULL;
    insertCFisrt(&head_circular,10);
    insertCFisrt(&head_circular,100);
    insertCFisrt(&head_circular,1000);
    insertCFisrt(&head_circular,100000);
    displayCirularList(&head_circular);
    return 0;
}


