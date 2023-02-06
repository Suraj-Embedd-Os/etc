#include <stdio.h>
#include<string.h>
#include<stdlib.h>

char *my_strtok( const char *str, const char *del)
{
    static char const *input=NULL;
    
    if(str!=NULL)
    input=str;
    
    if(input==NULL)
    return NULL;
    
    char *result=(char*)malloc((strlen(input)+1)*sizeof(char));
    
    int i=0;
    for(;input[i]!='\0';i++)
    {
        if(strncmp(&input[i],del,strlen(del))!=0)
        {
            result[i]=input[i];
        }
        else
        {
            result[i]='\0';
            input=input+i+strlen(del);
            
            return result;
            
        }
    }
    result[i]='\0';
    input=NULL;
    
    return result;
    
}

int main()
{
    
    char str[]="hello dear hii how";
    
   char *s=my_strtok(str," ");
   
   //printf("%s ",s);
   
   while(s)
   {
       printf("%s\n",s);
       s=my_strtok(NULL," ");
   }

    return 0;
}
