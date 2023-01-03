/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdarg.h>

int sum(int,...);

int main()
{
    printf("%d ",sum(4,4,5,5,5));

    return 0;
}
int sum(int num,...)
{
    va_list ap;
    
    int arg,tl=0;
    
    va_start(ap,num);
    
    for(int i=0;i<num;i++)
    {
        arg=va_arg(ap,int);
        printf("%d ",arg);
    tl+=arg;
    
    }
    
    va_end(ap);
    return tl;
}


