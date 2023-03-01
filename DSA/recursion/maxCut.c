
#include <stdio.h>

int max(int a,int b,int c)
{
    return (a>b?a>c?a:c:b>c?b:c);
}

int maxCut(int n,int a,int b,int c)
{
    if(n==0)
    return 0;
    if(n < 0 )
    return -1;
    
    
    int res= max(maxCut((n-a),a,b,c),maxCut((n-b),a,b,c),maxCut((n-c),a,b,c));
    
    if(res==-1) return -1;
    return res+1;
}

int main()
{
   printf("%d ",maxCut(23,11,9,12));

    return 0;
}
