
#include <stdio.h>


int rHCF(int m,int n)
{
    if(n==0)
    return m;
    rHCF(n,m%n);
    
}

int iHCF(int m,int n)
{
    int r;
    
    while(n>0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}

int LCM(int m,int n)
{
    int max=(m>n)?m:n;
    
    while(max % m!=0 && max %n !=0)
    max++;
    
    return max;
}


int main()
{
   printf("%d ",LCM(10,20));

    return 0;
}
