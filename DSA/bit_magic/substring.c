#include <stdio.h>
#include<string.h>
#include<math.h>

int printSubset(char *s)
{
    int n=strlen(s);
    
    int end=pow(2,n);
    
    for(int i=0;i<end;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((i & (1<<j)) !=0)
            printf("%c",s[j]);
        }
        printf("\n");
    }
    return 0;
    
}

int main()
{
  
     
   printSubset("abc");
    return 0;
}
