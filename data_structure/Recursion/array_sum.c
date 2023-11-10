
#include <stdio.h>

int arrSum1(int *arr,int lo,int hi)
{
    if(lo>hi)
    return 0;
    else
    return arr[hi]+arrSum1(arr,lo,hi-1);
}

int arrSum2(int *arr,int lo,int hi)
{
    if(lo>hi)
    return 0;
    else
    return arr[lo]+arrSum1(arr,lo+1,hi);
}

int arrSum3(int *arr,int lo,int hi)
{
    if(lo>hi)
    return 0;
    else if(lo==hi)
    return arr[lo];
    else
    {
        int mid=(lo+hi)/2;
        
        return arrSum3(arr,lo,mid)+arrSum3(arr,mid+1,hi);
    }
}

int main()
{
   int arr[10]={1,2,3,4,5,6,7,8,9,10};
   
   printf("%d %d %d",arrSum1(arr,0,9),arrSum2(arr,0,9),arrSum3(arr,0,9));

    return 0;
}
