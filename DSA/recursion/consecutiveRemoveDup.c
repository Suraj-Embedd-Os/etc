
#include <stdio.h>

void consecutiveRemoveDup(char *s)
{
    if(s[0] == '\0')
    return ;
    
    if(s[0]==s[1])
    {
            int i=1;
            for(;s[i] != '\0';i++)
            s[i-1]=s[i];
            
            s[i-1]=s[i];
            consecutiveRemoveDup(s);
            
    }
    else
    consecutiveRemoveDup(s+1);
    
  
}

int main()
{
    char str[]={"aaabbcc"};
    consecutiveRemoveDup(str);
    
    printf("%s ",str);

    return 0;
}
