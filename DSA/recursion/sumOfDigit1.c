
#include <stdio.h>

int sumOfDigit(int num,int acc)
{
    if(num == 0)
    return acc;
    else
    {
        acc +=num%10;
        return sumOfDigit(num/10,acc);
    }
}

int main()
{
    printf("%d ",sumOfDigit(123,0));

    return 0;
}
