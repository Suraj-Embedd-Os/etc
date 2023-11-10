

#include<stdio.h>
#include "type.h"

PROC proc[NPROC];

PROC *freeList;
PROC *readyQueue;
PROC *running;

#include "queue.c"

int kfork();
int kexit();
int do_kfork();
int do_switch();
int do_exit();
int body();
int init();
int scheduler();
void tswitch();




int kfork()
{
	int i;
	
	PROC *p=dequeue(&freeList);
	if(!p)
	{
		printf("No More proc\n");
		return (-1);
	}
	
	/* Initialize the new process and its stack size */

	p->status=READY;
	p->priority=1;
	p->ppid=running->pid;
	
	/************ new task initial stack contents ************
	kstack contains: |retPC|eax|ebx|ecx|edx|ebp|esi|edi|eflag|
	-1 -2 -3 -4 -5 -6 -7 -8 -9
	**********************************************************/
	
	for(int i=1; i<10;i++)
		p->kstack[SSIZE-i]=0; 		// zero out kstack cells
	p->kstack[SSIZE-1]=(int)body; 	// retPc->body();
	p->ksp= &(p->kstack[SSIZE-9]);  // PROC.ksp -> saved eflag
	
	enqueue(&readyQueue,p);
	return p->pid;
	
	
	
}

int kexit()
{
	running->status = FREE;
	running->priority =0;
	enqueue(&freeList,running);
	
	printList("freeList",freeList);
	
	tswitch();
	
}

int do_kfork()
{
	int child = kfork();
	
	if(child < 0)
		printf("Kfork failed\n");
	else
	{
		printf("proc %d kforked a child =%d\n",running->pid,child);
		printList("readyQueue",readyQueue);
	}
	
	return child;
}

int do_switch()
{
	tswitch();
}

int do_exit()
{
	kexit();
}


int body() // process body function
{
	int c;
	printf("proc %d starts from body()\n",running->pid);
	
	while(1)
	{
		printf("***************************************\n");
		printf("proc %d running: parent=%d\n", running->pid,running->ppid);
		printf("enter a key [f|s|q] : ");
		c = getchar(); getchar(); // kill the \r key
		switch(c)
		{
			case 'f': do_kfork(); break;
			case 's': do_switch(); break;
			case 'q': do_exit(); break;
		}
		
	}
	
}


// initialize the MT system; create P0 as initial running process

int init()
{
	int i;
	PROC *p;
	
	for(i=0;i<NPROC;i++)
	{
		p=&proc[i];
		p->pid=i;
		p->status=FREE;
		p->priority=0;
		p->next=p+1;
		
	
	}
	proc[NPROC-1].next=0;
	
	freeList=&proc[0];
	readyQueue=0;
	
	// create P0 as the initial running process
	
	p=running=dequeue(&freeList);
	p->status=READY;
	p->ppid=0;
	
	printList("freeList",freeList);
	
	printf("Init complete: P0 running\n");
	
}

/*************** main() function ***************/
int main()
{
	printf("Welcome to the MT Multitasking System\n");
	init(); // initialize system; create and run P0
	kfork(); // kfork P1 into readyQueue
	while(1)
	{
		printf("P0: switch process\n");
		if (readyQueue)
		tswitch();
	}
	
	return 0;
}


int scheduler()
{
	printf("proc %d in scheduler() \n",running->pid);
	
	if(running->status = READY)
	{
		enqueue(&readyQueue,running);
	}
	
	printList("readyQueue",readyQueue);
	
	running=dequeue(&readyQueue);
	
	printf("next running =%d\n",running->ppid);
	
}




