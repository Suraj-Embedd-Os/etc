#include <stdio.h>
#include<string.h>

int isPal(char *str,int low,int high)
{
   
   if(low>=high)
   return 1;
   
   if(str[low]!=str[high])
   return 0;
   else 
   return isPal(str,low+1,high-1);
}

int main()
{
   
  
   printf("%d ",isPal("abcbaq",0,5));

    return 0;
}