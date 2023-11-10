/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<ctype.h>

int StrToInt(char *str)
{
   char ch;
   int num=0;
   int i=0;
   while(str[i]!='\0')
   {
       //ch=getc(stdin);
       if(!isdigit(str[i]))
       break;
       
       num=num*10+str[i]-'0';
       i++;
      
   }
   
  return num;
}

int main()
{
   
   printf("%d " ,StrToInt("1335@111"));
    return 0;
}
