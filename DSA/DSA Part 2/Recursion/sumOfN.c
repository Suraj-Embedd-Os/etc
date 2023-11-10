#include <stdio.h>

int sumofN(int n)
{
    if(n==0)
    {
        return n;
    }
   
   return n+sumofN(n-1);
   
}

int main()
{
    printf("%d \n",sumofN(10));
    return 0;
}
