/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void reverse_word(char *begin,char *end)
{
    char temp;
    while(begin<end)
    {
      temp=*begin;
      *begin=*end;
      *end=temp;
      ++begin;
      --end;
    }
}

void reverse_sentence(char *str)
{
    char *begin=str;
    char *temp=str;
    
    while(*temp)
    {
        temp++;
        if(*temp=='\0')
			reverse_word(begin,temp-1);
        else if(*temp==' ')
        {
			reverse_word(begin,temp-1);
			begin=temp+1;
        }
    }
    reverse_word(str,temp-1);
}

int main()
{
    char str[]="i love programming very much";
    
    reverse_sentence(str);
    
    printf("%s ",str);
   
    
    return 0;
}
