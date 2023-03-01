
#include <stdio.h>
#include<string.h>
#include<math.h>



int findMissingNumber(int *arr,int arr_size,int range)
{
    int num=0;
    for(int i=0;i<arr_size;i++)
    {
        num ^=arr[i];
    }
    
    for(int i=1;i<=range;i++)
    {
       num ^=i; 
    }
    
    
    return num;
}

int main()
{
        int arr[]={1,4,3,6,7,2};
        
       // int a=3^5;
        
        printf("%d",findMissingNumber(arr,sizeof(arr)/sizeof(arr[0]),7));
    
    return 0;
}
