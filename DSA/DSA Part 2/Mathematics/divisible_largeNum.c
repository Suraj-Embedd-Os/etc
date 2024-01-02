
#include <stdio.h>


int check(const char *str)
{
    int num=0;
int i=0;

    while(str[i]!='\0')
    {
        num +=(str[i]-'0');
        i++;
    }
    
    return (num%3==0?1:0);
}

int main()
{
    
    char *str="123";
    
    printf("%d ",check(str));
    return 0;
}
