
#include <stdio.h>

int longestOne(int *arr,int num)
{
    int longestLen=0;
    int beforeZero=0,afterZero=0;
     int len=0;
    
    for(int i=0;i<num;i++)
    {
        if(arr[i]==1)
        {
            afterZero++; 
            
        }
        else
        {
            len=beforeZero + afterZero +1;
            longestLen=len>longestLen?len:longestLen;
            beforeZero=afterZero;
            afterZero=0;
        }
    }
    
   return (beforeZero + afterZero +1)>longestLen?(beforeZero + afterZero +1):longestLen;
    
}

int main()
{
    int arr[10]={1,0,1,1,0,0,1,1,0,1};
    
    printf("%d ",longestOne(arr,10));

    return 0;
}
