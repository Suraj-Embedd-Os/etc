
#include <stdio.h>

void print_binary(int num,int base);

int insertbit(int num,int m,int i, int j)
{
   
   int allones = ~0;
   
   int right = allones<<(j+1);
   
   int left =1<<i;
   
   int mask = left | right;
   
   int n_cleanBit = num & mask;
   
   int m_shiftbit = m<<i;
   
   return n_cleanBit|m_shiftbit;
    
}

int main()
{
    
    int a=0x100;
    int m=0x5;
    
    print_binary(a,16);
    print_binary(m,16);
    int k= insertbit(a,m,4,6);
    print_binary(k,16);
    
    return 0;
}

void print_binary(int num,int base)
{
    
    for(int i=base-1;i>=0;i--)
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
