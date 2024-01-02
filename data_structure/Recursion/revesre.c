void reverse(int num)
{
    if(num>0)
    {
            printf("%d",num%10);
            reverse(num/10);
    }
}

int main()
{
   
    reverse(123);
    return 0;
}


#include <stdio.h>

void convert(int num,int base)
{
   if(num>0)
   {
      convert(num/base,base);
      if(num%base>=10)
      {
          printf("%c",num%base-10+'A');
      }
      else
      printf("%d",num%base);
   }
    
}

int main()
{
   
    convert(10,16);
    return 0;
}
