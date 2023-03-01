
#include <stdio.h>
#include <string.h>

int longestsubsPalindrom(char *s)
{
    int subLen,tempLen=0;
    int len=strlen(s);
    
    char map[256];
    memset(map,0,256);
    
    int i=0,left,right;
    
    while(i<len)
    {
        left=i-1;
        right=i+1;
        
        while(left >=0 && right <len)
        {
            if(s[left]!=s[right])
            {
                break;
            }
            
            tempLen=right-left+1;
            subLen=tempLen>subLen?tempLen:subLen;
            left--;
            right++;
           
        }
        i++;
        
       
    }
    
    subLen=tempLen>subLen?tempLen:subLen;
    
    return subLen;
}


int main()
{
    char *s="madamabcdcba";
    printf("%d ",longestsubsPalindrom(s));

    return 0;
}
