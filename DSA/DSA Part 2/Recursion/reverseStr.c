
#include <stdio.h>

void reverseStr(char *str,int start,int end)
{
   if(start>=end)
   return;
   
   int temp=str[start];
   str[start]=str[end];
   str[end]=temp;
   
   reverseStr(str,start+1,end-1);
   
   
}

int main()
{
    char str[]="hello";
    reverseStr(str,0,4);
    
    printf("%s ",str);
    return 0;
}
