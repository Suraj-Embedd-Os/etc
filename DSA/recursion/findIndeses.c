#include<stdlib.h>
#include<stdio.h>

int ind_arr[10],k=0;

int findIndes(int *arr,int arr_size,int key)
{
    if(arr_size==0)
    return 0;
    
    int a=findIndes(arr+1,arr_size-1,key);
    
    if(arr[0]==key)
    {
        ind_arr[k++]=a;
       
        return a+1;
        
    }
    
    return a+1;
}

int main()
{
    int a[]={1,2,5,4,3,5,7,5};
    int s=0;
    
    int c=findIndes(a,sizeof(a)/sizeof(int),5);
    
    for(int i=0;i<c;i++)
    printf("%d ",ind_arr[i]);

    return 0;
}