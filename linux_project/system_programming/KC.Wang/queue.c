
//#include "type.h"

int printList(char *name ,PROC *p);
PROC *dequeue(PROC **queue);
int enqueue(PROC **queue,PROC *p);


int enqueue(PROC **queue,PROC *p)
{
	PROC *q=*queue;
	
	if(q==0 || q->priority > p->priority)
	{
		*queue=p;
		p->next=q;
	}
	else
	{
		while(q->next && q->priority > p->priority)
			q=q->next;
		
		p->next=q->next;
		q->next = p;
		
	}
}


PROC *dequeue(PROC **queue)
{
	PROC *q=*queue;
	
	if(q)
		*queue = (*queue)->next;
	
	return q;
}

int printList(char *name ,PROC *p)
{
	printf("%s = ",name);
	while(p)
	{
		printf("[%d %d]->",p->pid,p->priority);
		p=p->next;
	}
	
	printf("NULL\n");
}


