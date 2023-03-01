#include <stdio.h>

int fact(int n,int k)
{
   if(n==0)
   return k;
    return fact(n-1,n*k); 
}

int main()
{
   
  
   printf("%d ",fact(5,1));

    return 0;
}
