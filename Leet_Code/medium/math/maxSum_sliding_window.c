
#include <stdio.h>

int maxSum(int *arr,int arrSize,int term)
{
    int sum=0;
    for(int i=0;i<arrSize;i++)
    {
        if(i<term)
        sum+=arr[i];
        else
        {
            if((arr[i]+sum-arr[i-term])>sum)
            sum=arr[i]+sum-arr[i-term];
        }
    }
    
    return sum;
}

int main()
{
    
    int arr[10]={111,2,3,4,5,6,7,8,9,10};
    printf("%d ",maxSum(arr,10,2));

    return 0;
}
