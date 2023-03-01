
#include <stdio.h>


int way(int n,int *arr,int arr_size)
{
    if(n ==0)
    return 1;
    
    int ways=0;
    
    for(int i=0;i<arr_size;i++)
    {
        if(n-arr[i] >=0)
          ways +=way(n-arr[i],arr,arr_size);
    }
    
    return ways;
    
}

int main()
{
    int a[]={2,4,5,8};
    
    printf("%d ",way(10,a,4));

    return 0;
}
