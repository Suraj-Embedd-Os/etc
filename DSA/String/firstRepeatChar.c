
#include <stdio.h>
#include<limits.h>
#include<string.h>

int firstRepeatChar(char *str)
{
    int res=INT_MAX;
    
    int FI[256];
    //memset(FI,-1,sizeof(res));
    
    for(int i=0;i<256;i++)
    FI[i]=-1;
        
    for(int i=0;i<strlen(str);i++)
    {
        if(FI[str[i]]==-1)
        FI[str[i]]=i;
        else
        res=res<FI[str[i]] ?res:FI[str[i]];
        
    }
    
    return (res==INT_MAX?-1:res);
}

int main()
{
    printf("%d ",firstRepeatChar("abcdefbc"));

    return 0;
}
