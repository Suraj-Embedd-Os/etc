
void reverseString(char *str)
{
    char *end=str;
    char temp;
    
    if(str)
    {
       while(*end)
       end++;
    }
    end--;
    
    while(str<end)
    {
        temp=*str;
        *str++=*end;
        *end--=temp;
    }
}
/**********************************************************************************************************************/
#include <stdio.h>
#include<stdbool.h>

void bubblesort(char *str,int len)
{
    int i=0,j;
    char temp;
    for(i=0;i<len-1;i++)
    {
        for(j=i+i;j<len;j++)
        {
            if(str[i]>str[j])
            {
                temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
    }
}

bool isequalstr(char *str1,char *str2)
{
    int i=0;
    while(str1[i]!=0 && str2[i]!=0)
    {
        if(str1[i]!=str2[i])
        return false;
        i++;
    }
    return true;
}

bool ischeckAangram(char *str1,char *str2)
{
    int len1=0,len2=0;
    int i=0,j;
    while(str1[i]!='\0')
    {
       len1++;
       i++;
    }
    i=0;
    while(str2[i]!='\0')
    {
       len2++;
       i++;
    }
    
    printf("%d %d \n",len1,len2);
    if(len1!=len2)
    {
    printf("not\n");
    return false;
    
    }
    
    bubblesort(str1,len1);
    bubblesort(str2,len2);
    
    printf("%s %s\n",str1,str2);
    
    if(isequalstr(str1,str2))
    {
        printf("ana\n");
    }
    else
    printf("not\n");
}

int main()
{
    char str1[]="cot";
    char str2[]="tac";
    
    ischeckAangram(str1,str2);
    return 0;
}
/**********************************************************************************************************************/