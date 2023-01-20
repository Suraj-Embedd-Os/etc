
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void copy(char *src,char *des,int low,int high)
{
	
    for(int i=low;i<=high;i++){
        *des=src[i];
        des++;
    }
	*des='\0';
}

char * longestPalindrrom(char *s)
{
    int len=strlen(s);
    
    if(len==0)
    return NULL;
    char *arr=(char *)calloc(len+1,sizeof(char));
	
	if(len==1)
	{
		arr[0]=s[0];
		arr[1]='\0';
		return arr;
	}
    
    int maxLenght=1;
    int start=0;
    int low,high;
    
    for(int i=0;i<len;i++)
    {
        low=i-1;
        high=i+1;
        
        while(high<len && s[i]==s[high])
        high++;
        
        while(low>=0 && s[i]==s[low])
        low--;
        
        while(low>=0 && high<len && s[low]==s[high])
        {
            low--;
            high++;
        }
        
        int lenght=high-low-1;
        if(maxLenght<lenght)
        {
            maxLenght=lenght;
            start=low+1;
        }
        
    }
	
    copy(s,arr,start,start+maxLenght-1);
    
    return arr;
}

int main()
{
    char *arr=longestPalindrrom("madam");
    
    printf("%s ",arr);

    return 0;
}
