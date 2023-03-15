
#include <stdio.h>
#include<string.h>

int memo[500];


int fib(int n)
{
   if(memo[n]==-1)
   {
       int res;
       if(n==0 || n==1)
         res=n;
       else
           res=fib(n-1)+fib(n-2);
           
        memo[n]=res;
       
   }
   return memo[n];
}

int main()
{
  
  for(int i=0;i<500;i++)
     memo[i]=-1;

    printf("%d ",fib(6));
    return 0;
}
