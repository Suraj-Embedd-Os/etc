#include <stdio.h>

int sumOfDigit(int num)
{
    if(num<10)
    return num;
    return sumOfDigit(num/10)+num%10;
}

int main()
{
    printf("%d ",sumOfDigit(123));

    return 0;
}
