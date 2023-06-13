#include <stdio.h>

int countDigit(int n)
{
    if(n==0)
    {
        return 0;
    }
    int digit =n%10;
    int count=countDigit(n/10);
    return digit+count;
   
}

int main()
{
    printf("%d \n",countDigit(12345));
    return 0;
}
