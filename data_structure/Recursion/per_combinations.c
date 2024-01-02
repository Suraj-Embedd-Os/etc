#include <stdio.h>

int factorial(int n);
int permuntation(int n,int r);
int combination(int n,int r);

int main()
{
    printf("%d  %d ",permuntation(10,4),combination(10,4));
    return 0;
}


int factorial(int n)
{
    if(n==0||n==1)
    return 1;
    else
    return n*factorial(n-1);
}

int permuntation(int n,int r)
{
    return factorial(n)/factorial(n-r);
}

int combination(int n,int r)
{
    return permuntation(n,r)/factorial(r);
}
