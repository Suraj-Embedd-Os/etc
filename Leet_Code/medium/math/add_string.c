void reverseStr(char *str)
{
    int len=strlen(str);
    
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        int c=str[i];
        str[i]=str[j];
        str[j]=c;
    }
}

char *add(char *str1,char *str2)
{
    int c=0;
    int r=0;
    int k=0;
    
   
    reverseStr(str1);
    reverseStr(str2);
    
    char *result=(char *)malloc((strlen(str1)+strlen(str2)+2)*sizeof(char));

    
    while(*str1!='\0' && *str2!='\0')
    {
        r=((*str1-'0')+(*str2-'0')+c)%10;
        c=((*str1-'0')+(*str2-'0'))/10;
        
        printf("%d %d \n",r,c);
        result[k++]=r+'0';
        str1++;
        str2++;
        
    }
    
    while(*str1!='\0')
    {
     result[k++]=*str1;
     str1++;
    }
    
     while(*str2!='\0')
    {
     result[k++]=*str2;
     str2++;
    }
    
    
    
    result[k]='\0';
    
    reverseStr(result);
    return result;
    
}