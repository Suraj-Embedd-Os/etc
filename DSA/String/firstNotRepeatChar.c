
#include <stdio.h>
#include<string.h>
#include<limits.h>


int firstNotRepeatChar(char *s1)
{
    int res=INT_MAX;
    int FI[256];
   
    for(int i=0;i<256;i++)
    {
       FI[i]=-1;
    }
    
    for(int i=0;i<strlen(s1);i++)
    {
        if(FI[s1[i]]==-1)
         FI[s1[i]]=i;
         else
         FI[s1[i]]=-2;
    }
    
    for(int i=0;i<256;i++)
    {
       if(FI[i]>=0)
       res = res<FI[i]?res:FI[i];
    }
    
    return (res==INT_MAX?-1:res);
}

int main()
{
    printf("%d ",firstNotRepeat("abcabc"));

    return 0;
}
