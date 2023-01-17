/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void print_bin(int num);


int main()
{
    int a=4;
    int b=5;
    int c=a^b;
    
    int pos1=0;
    int pos2=1;
    
    print_bin(b);
    b=(b & 1<<pos1)?(b & 1<<pos2)?c:(b ^=(1<<pos1)):(b ^=(1<<pos2));
    
    
    //print_bin(a);
    print_bin(b);
    //print_bin(c);
    
    return 0;
}


void print_bin(int num)
{
    for(int i=15;i>=0;--i)
    {
        if(num & 1<<i)
        printf("1");
        else
        printf("0");
        
        if(i%4==0)
        printf(" ");
    }
    printf("\n");
}
