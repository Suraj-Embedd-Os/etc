char *my_strtok(char *str,char deli)
{
        static char *input=NULL;
        
        if(str!=NULL)
        input=str;
        
        if(input==NULL)
        return NULL;
        
        char *result =(char *)malloc(strlen((input)+1)*sizeof(char));
        
        int i=0;
        for(;input[i]!='\0';i++)
        {
            if(input[i]!=deli)
            result[i]=input[i];
            else
            {
                result[i]='\0';
                input=input+i+1;
                return result;
            }
        }
        result[i]='\0';
        input=NULL;
        
        return result;
        
}


char *my_strtok(char *str,char *deli)
{
        static char *input=NULL;
        
        if(str!=NULL)
        input=str;
        
        if(input==NULL)
        return NULL;
        
        char *result =(char *)malloc(strlen((input)+1)*sizeof(char));
        
        int i=0;
        for(;input[i]!='\0';i++)
        {
            if(strncmp(&input[i],deli,strlen(deli))!=0)
            result[i]=input[i];
            else
            {
                result[i]='\0';
                input=input+i+strlen(deli);
                return result;
            }
        }
        result[i]='\0';
        input=NULL;
        
        return result;
        
}
