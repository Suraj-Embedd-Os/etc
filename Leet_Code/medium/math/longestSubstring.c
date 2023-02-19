
#include <stdio.h>
#include <string.h>

int longestSubstring(char *s)
{
    int subLen=0;
    int len=0;
    
    char map[256];
    memset(map,0,256);
    
    int i=0,j=0;
    
    while(i<strlen(s))
    {
       map[s[i]]++;
       
       while( map[s[i]]>1)
       {
          map[s[j]]--;
          j++;
       }
       
       len=i-j+1;
       
       subLen=len>subLen?len:subLen;
       i++;
       
    }
    
    return subLen;
}


int main()
{
    char *s="abcabcd";
    printf("%d ",longestSubstring(s));

    return 0;
}
