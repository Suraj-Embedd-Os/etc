#include <stdio.h>

int countDigit(int n)
{
    if(n==0)
    {
        return 0;
    }
   
    int count=countDigit(n/10);
    return 1+count;
   
}

int main()
{
    printf("%d \n",countDigit(1000));
    return 0;
}
