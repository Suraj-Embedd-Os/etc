
#include <stdio.h>

void removeX(char *s)
{
    if(s[0] == '\0')
    return ;
    
    if(s[0] != 'x')
    removeX(s+1);
    else {
        int i=1;
        for(;s[i]!='\0';i++)
        {
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        
         removeX(s);
    }
}

int main()
{
    char str[]={"xabxcd"};
    removeX(str);
    
    printf("%s ",str);

    return 0;
}
