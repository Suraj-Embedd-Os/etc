
#include <stdio.h>
#include<string.h>


int isanGram(char *s1,char *s2)
{
    if(strlen(s1)!=strlen(s2))
    return 0;
    
    unsigned char count[256]={0};
    memset(count,0,256);
    for(int i=0;i<strlen(s1);i++)
    {
        count[s1[i]]++;
    }
    for(int i=0;i<strlen(s2);i++)
    {
        count[s2[i]]--;
    }
    
    for(int i=0;i<256;i++)
    {
        if(count[i]!=0)
        return 0;
    }
    return 1;
}

int main()
{
    printf("%d ",isanGram("abcabc","bcaabc"));

    return 0;
}
