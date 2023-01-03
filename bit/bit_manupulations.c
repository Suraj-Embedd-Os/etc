/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdint.h>

void print_bit_pattern(int num,int bit_lenght);


int main()
{
    int8_t bit=0b01010101;
     printf("%d \n",bit);
    print_bit_pattern(bit,sizeof(bit)*8);
    int i;
  
    
    for(i=0;i<8;i++){
    if((bit & 1<<i))
    break;
    }
    for(int j=i+1;j<8;j++)
     bit ^=(1<<j); 
    
 print_bit_pattern(bit,sizeof(bit)*8);
   
    printf("%d ",bit);

    return 0;
}


void print_bit_pattern(int num,int bit_lenght)
{
    
    for(int i=bit_lenght-1;i>=0;i--)
    {
        
        if(num & 1<<i)
        printf("%d",1);
        else
        printf("%d",0);
        
        if(i%4==0)
         printf(" ");
        
        
    }
    printf("\n");
}
