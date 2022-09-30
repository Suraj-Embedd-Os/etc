#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<caca.h>
#include <sys/ioctl.h>
#include <termios.h>


int main()
{
   while(1)
   {
       while(!kbhit())
       {
          //works continuously until interrupted by keyboard input.
          printf("M Tired. Break Me\n");
		  sleep(1);
       }
       system("clear");
   }
   return 0;
}

