
#include <stdio.h>
#include<string.h>

void swap(char *str,int l,int h)
{
    str[l]=str[l]^str[h];
    str[h]=str[l]^str[h];
    str[l]=str[l]^str[h];
}

void reverseWord(char *str)
{
    int len=strlen(str);
    int s=0,e=0,last=0;
    
        while(str[e]!='\0')
        {
   
            while(str[s] ==' '){
            s++;
            e++;
            }
            while(str[e+1] != ' ' &&  str[e+1] != '\0')
            e++;
            
            last=e;
            while(s<e)
            {
                swap(str,s,e);
                s++;
                e--;
            }
            last++;
            e=s=last;
        }
    
}

int main()
{
   char str[]="Welcome to GDB Online";

    reverseWord(str);
    
    printf("%s ",str);
    return 0;
}
