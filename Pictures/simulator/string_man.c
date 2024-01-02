/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<string.h>

void getStr(char *src,char *des,char *find)
{
    int i=0;
    int j=0;
    int flag=0;
    while(src[i]!='\0')
    {
        if(strncmp(&src[i],des,strlen(find))==0)
        {
            flag=1;
            j=strlen(find);
            i+=j;
            j=0;
            while(src[++i]!=':')
            des[j++]=src[i];
            des[j]='\0';
            break;
            
        }
        i++;
    }
    if(flag==0)
    {
        strcpy(des,"not found");
    }
}
char str[]="std:1234:md:14:id:10047:";
int main()
{
    
    int j=&str[5]-&str[0];
    char des[20];
	char find[20]="id";
   getStr(str,des,find);
   
   printf("%s",find);
    
    return 0;
}
