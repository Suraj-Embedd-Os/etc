#include <stdio.h>
#include<string.h>
#include<stdint.h>

int isaligramString(char *str1,char *str2)
{
    if(strlen(str1)!=strlen(str2))
    return 0;
    
    uint8_t hasTable[256]={0};
    
    while(*str1!='\0' || *str2!='\0')
    {
        if(*str1!='\0')
        {
          hasTable[*str1]++;
          str1++;
        
        }
        
        if(*str2!='\0')
        {
             hasTable[*str2]++;
             str2++;
        
        }
       
    }
 
    
    for(int i=0;i<256;i++)
    {
        if(hasTable[i]%2!=0)
        return 0;
    }
    
    
    return 1;
    
    
}

int main()
{
   int a=45;

    printf("%d ",isaligramString("silent","listen"));
   
    return 0;
}
