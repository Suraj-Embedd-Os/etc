/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void removeVowel(char *buff)
{
    int k=0;
   for(int i=0;buff[i]!='\0';i++)
   {
       if(buff[i]!='a'&& buff[i]!='e'&&buff[i]!='i'&&buff[i]!='o'&&buff[i]!='u')
       buff[k++]=buff[i];
   }
   buff[k]='\0';
}

int main()
{
   char buff[200];
   printf("Enter string : ");
   
   fgets(buff,20,stdin);
    removeVowel(buff);
    puts(buff);
    return 0;
}
