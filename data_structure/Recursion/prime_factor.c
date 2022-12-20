#include <stdio.h>

void pfactor(int num)
{
    for(int i=2;num!=1;i++)
    {
        while(num%i==0)
        {
            printf("%d ",i);
            num /=i;
        }
    }
}

void rfactor(int num)
{
    static int i=2;
   if(num==1)
   return;
   else
   {
       while(num%i==0)
       {
           printf("%d ",i);
           num /=i;
       }
       i++;
       rfactor(num);
   }
    
}

int main()
{
   
    rfactor(49);
    return 0;
}