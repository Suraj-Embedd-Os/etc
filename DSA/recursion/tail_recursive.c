
/*
    convet non tail recursive function to tail recursive
*/

#include <stdio.h>

int fib(int n,int a0,int a1,int result)
{
    if(n<=1)
    return n;
    else if(n==2)
    return result;
    else
    {
        a0=a1;
        a1=result;
        result=a0+a1;
        return fib(n-1,a0,a1,result);
        
    }
}

int sumOfN(int n,int acc)
{
    if(n==0)
    return acc;
    else return sumOfN(n-1,acc+n);
}

int power(int a,int b,int acc)
{
    if(b==0)
    return acc;
    else return power(a,b-1,a*acc);
}


int main()
{
    printf("%d ",sumOfN(5,0));

    return 0;
}

#include <stdio.h>
#include<limits.h>

int min(int a,int b)
{
    return (a>b?b:a);
}

int getMinArr(int *a,int arr_size,int min_val)
{
    if(arr_size==0)
    return min_val;
    else
        return getMinArr(a+1,arr_size-1,min(a[0],min_val));
}

int main()
{
    int a[]={11,7,56,8,95,14,6};
    printf("%d ",getMinArr(a,7,INT_MAX));

    return 0;
}
