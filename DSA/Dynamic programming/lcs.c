
#include <stdio.h>
#include<string.h>

int max(int a,int b)
{
    return (a>b?a:b);    
}

int lcs(char *s1,char *s2,int n,int m)
{
    if(n==0 || m==0)
    return 0;
    
    if(s1[n-1]==s2[m-1])
    {
        return 1+lcs(s1,s2,n-1,m-1);
    }
    else
     return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
    
}

int main()
{
   
   char *s1="abc";
   char *s2="axbxc";
   
   printf("%d ", lcs(s1,s2,strlen(s1),strlen(s2)));

    return 0;
}
