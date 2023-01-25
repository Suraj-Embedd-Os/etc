/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *start,char *end)
{
    while(start<end)
    {
        char temp=*start;
        *start++=*end;
        *end--=temp;
    }
}
 char result[50];
char * addBinary(char * a, char * b)
{
    int c=0;
    int r=0;
    int t=0;
    
    int len1=strlen(a)-1;
    int len2=strlen(b)-1;
   
    
    int k=0;
    
    while(len1>=0 && len2 >=0)
    {
        t=((a[len1]-'0')+(b[len2]-'0')+c);
        r = t%2;
        c= t/2;
        
        result[k++]=r+'0';
        
        len1--;
        len2--;
        
    }
    

    while(len1>=0)
    {
        t=((a[len1]-'0')+c);
        r=t%2;
        c=t/2;
        result[k++]=r+'0';
        len1--;
    }
    
     while(len2>=0)
    {
        t=((b[len2]-'0')+c);
        r=t%2;
        c=t/2;
         result[k++]=r+'0';
         len2--;
    }
    
    if(c!=0)
     result[k++]=c+'0';
    
    result[k]='\0';
    
    reverse(result,result+k-1);
    return result;
}

int main()
{
   
    char a[]="1";
    char b[]= "111";
    char *c=addBinary(a,b);
   
   
   printf("%s ",c);

    return 0;
}
