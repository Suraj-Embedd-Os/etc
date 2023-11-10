#include <stdio.h>

int countSetBit(int n)
{
    int res=0;
    /*while(n>0)
    {
        n = (n&(n-1));
        res++;
    }*/
    
   /* while(n>0)
    {
        if(n%2!=0)
        res++;
        n/=2;
    }*/
    
    return res;
    
    
   
}

int main()
{
    printf("%d",countSetBit(7));

    return 0;
}