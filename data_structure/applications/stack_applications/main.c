

#include<stdio.h>
#include<stdlib.h>
#include "list/linkList.h"
#include "stack/stack.h"
#include "queue/queue.h"


int main()
{
	
	struct stack *st_ptr=(struct stack *)malloc(1*sizeof(struct stack ));
	printf("stack appliation testing\n");
	push(&st_ptr,10);
	push(&st_ptr,100);
	push(&st_ptr,1000);
	displayStack(&st_ptr);
	
	return 0;
}