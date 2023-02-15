

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <signal.h>
#include <sys/types.h>
#
 
 void handler(int num)
 {
	 printf("ctrl+c detected \n");
	 execl("/mnt/d/suraj/etc/etc/linux_project/testing/remote.sh","1",NULL);
	 exit(0);
 }


int main()
{
	
	 signal(SIGINT,handler);
	 
	 while(1)
	 {
		 printf("main programm \n");
		 sleep(1);
	 }
		
}

