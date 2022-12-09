
#define _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>


void sigHandler(intr sig);

int main(void)
{
	
	pid_t pdi;
	pid=getpid();
	
	   struct sigaction action;
	   sigset_t set;
	  action.sa_handler=sigHandler;
	  printf("Program running with PID %d\n", pid);
	  
	   {
       void     (*sa_handler)(int);
       void     (*sa_sigaction)(int, siginfo_t *, void *);
       sigset_t   sa_mask;
       int        sa_flags;
       void     (*sa_restorer)(void);
   };
	return 0;
}
