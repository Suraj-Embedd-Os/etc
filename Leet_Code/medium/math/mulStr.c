
#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
#include<string.h>

char * reverseStr(char *str)
{
    int high=strlen(str)-1;
    int low=0;
    while(low<high)
    {
        int ch=str[low];
        str[low]=str[high];
        str[high]=ch;
        low++;
        high--;
    }
    
    return str;
}

int strToint(char *str)
{
    int i=0;
    int num=0;
    while(*str!='\0')
    {
        if((double)INT_MAX/num<=10.0)
        return 0;
        num = num*10+*str-'0';
        
        str++;
    }
    return num;
}

char * intToStr(int num)
{
   
    int len=0;
    int temp=num;
    char *numStr=NULL;
    
    if(temp==0)
    {
        len=1;
        numStr=(char *)malloc((len+1)*sizeof(char));
        numStr[0]='0';
        numStr[1]='\0';
        
        return numStr;
        
    }
    else
    {
        while(temp)
        {
            temp/=10;
            len++;
        }
        numStr=(char *)malloc((len+1)*sizeof(char));

    
    
    char *temp_str=numStr;
    
    
    while(num)
    {
        *temp_str='0'+num%10;
        temp_str++;
        num/=10;
    }
    *temp_str='\0';
    
    return reverseStr(numStr);
    
    }
 
}

char * multiply(char * num1, char * num2)
{
   if(num1==NULL || num2==NULL)
   return NULL;
   
   int num=strToint(num1)*strToint(num2);
   
   if(num<0)
   return NULL;
   else
   return intToStr(num); 
}

int main()
{
    printf("%d ",strToint("0"));
    
    printf("%s ",multiply("123456789","987654321"));

    return 0;
}
