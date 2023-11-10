

#ifndef __TYPE_H_
#define __TYPE_H_


#define NPROC	9
#define SSIZE	1024

//proc status
#define FREE	0
#define READY	1
#define SLEEP	2
#define ZOMBIE	3


typedef struct proc	{
	struct proc *next;				//next proc pointer
	int *ksp;						//Saved stack pointer
	int pid;						//pid = 0 to NPROC-1
	int ppid;						//parent pid
	int status;						//PROC status
	int priority;					//Scheduling priority
	int kstack[SSIZE];				//Process stack
	
}PROC;


#endif