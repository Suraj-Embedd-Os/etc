

#include <stdio.h>

int binarySearch(int *arr,int key,int start,int end)
{
    if(start>end)
    return -1;
    
    int mid=(start+end)/2;
    
    if(arr[mid]==key)
    return key;
    else if(key<arr[mid])
    {
        return binarySearch(arr,key,start,mid-1);
    }
    else
    return binarySearch(arr,key,mid+1,end);
}

int main()
{
   int a[]={1,2,3,4,5,6};
   
   printf("%d ",binarySearch(a,4,0,5));

    return 0;
}
