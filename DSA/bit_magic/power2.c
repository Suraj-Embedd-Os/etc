#include <stdio.h>

int isPow2(int n)
{
    
    return ((n != 0) &&((n & (n-1))==0));
}

int main()
{
    printf("%d",isPow2(2));

    return 0;
}