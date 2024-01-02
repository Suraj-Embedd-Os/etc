
#include <stdio.h>
#include<limits.h>


int maxDiff(int *arr,int arr_size);

int main()
{
    int arr[]={2,3,8,10,6,4,8,1};
    
    printf("%d ",maxDiff(arr,sizeof(arr)/sizeof(int)));

    return 0;
}


int maxDiff(int *arr,int arr_size)
{
    int max=INT_MIN;
    int min=INT_MAX;
    for(int i=0;i<arr_size;i++)
    {
           if(arr[i]>max)
           max=arr[i];
           
           if(arr[i]<min)
           min=arr[i];
    }
    
    return max-min;
}
