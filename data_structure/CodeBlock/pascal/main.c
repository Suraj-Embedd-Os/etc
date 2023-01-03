#include <stdio.h>
#include <stdlib.h>

int fact(int n);
int combination(int n,int r);

int main()
{


    for(int i=0;i<10;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("%d ",combination(i,j));
        }
        printf("\n");
    }
    return 0;
}


int fact(int n)
{
    int res=1;
    for(int i=1;i<=n;i++)
    {
        res*=i;
    }

    return res;
}

int combination(int n,int r)
{
    int res=0;
    res=fact(n)/(fact(r)*(fact(n-r)));

    return res;
}
