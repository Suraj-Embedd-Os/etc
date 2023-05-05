#include <stdio.h> 
#include <stdlib.h> 
#include <sys/time.h>
#include <time.h>



int main()
{
   struct timeval t;
   
   gettimeofday(&t,NULL);
   
   printf("%ld %ld \n",t.tv_sec,t.tv_usec);
  printf("%s", ctime(&t.tv_sec));


    return 0;
}
