#include<stdio.h>

int find(int *arr,int key,int size)
{
    if(size==0)
    return -1;
    
    if(arr[0]==key)
    return 0;
        
    int a=find(arr+1,key,size-1);
    
    if(a==-1)
    return a;
    else
    return a+1;
    
}

int main()
{
    int a[]={1,2,3,4,5};
    
    printf("%d ",find(a,4,5));

    return 0;
}
