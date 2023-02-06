/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<string.h>

int max(int a,int b)
{
    
    return (a>b ?a:b);
}

int checkRepetations(char *s,int start,int end)
{
    unsigned char arr[128];
    memset(arr,0,128);
    
    for(;start<=end;start++)
    {
        if(arr[s[start]]!=0)
        return 0;
        else
        arr[s[start]]++;
        
    }
    return 1;
}

int longestSubstring(char *str)
{
    int n=strlen(str);
    int res=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(checkRepetations(str,i,j))
            {
             res=max(res,j-i+1);
            // printf("%d ",res);
            }
        }
    }
    
    return res;
}

int main()
{
    char *str="abcabcdfff";
    
    printf("%d ",longestSubstring(str));
    return 0;
}
