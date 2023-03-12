
#include <stdio.h>

int firstOcc(int *arr,int arr_size,int key)
{
    if(arr_size==0)
    return -1;
    
    if(arr[0]==key)
    return 0;
    int a=firstOcc(arr+1,arr_size-1,key);
    
    if(a != -1)
    return a+1;
    else
    return a;
    
}

int main()
{
    int a[]={1,2,3,3,44,5,5,6};
    
    printf("%d ",firstOcc(a,sizeof(a)/sizeof(int),5));

    return 0;
}
