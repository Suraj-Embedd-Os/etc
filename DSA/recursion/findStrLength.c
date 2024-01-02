
#include <stdio.h>

int findLength(char *str)
{
    if(*str == '\0')
    return 0;
    
    int len=findLenght(str+1);
    
    return len+1;
}

int main()
{
    printf("%d ",findLenght("asas"));

    return 0;
}
