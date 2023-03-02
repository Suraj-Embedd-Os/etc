
#include <stdio.h>
#include<stdlib.h>


int reverse(int *arr,int s,int e)
{
    if(s>=e)
    return 0;
     int a=arr[s];
     arr[s]=arr[e];
     arr[e]=a;
     
     reverse(arr,s+1,e-1);
}
int leftRotate_1(int *arr,int arr_len,int shift);

int leftRotate_2(int *arr,int arr_len,int shift)
{
    reverse(arr,0,arr_len-1);
    reverse(arr,0,arr_len-shift-1);
    reverse(arr,arr_len-shift+1,arr_len-1);
    
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    
    leftRotate_2(arr,6,2);
    
    for(int i=0;i<6;i++)
    printf("%d ",arr[i]);

    return 0;
}

int leftRotate_1(int *arr,int arr_len,int shift)
{
    int *temp=(int*)malloc(shift*sizeof(int));
    
    for(int i=0;i<shift;i++)
    temp[i]=arr[i];
    
    for(int i=shift;i<arr_len;i++)
    {
        arr[i-shift]=arr[i];
    }
    
    for(int i=0;i<shift;i++)
    {
        arr[arr_len-shift+i]=temp[i];
    }
    
    return 0;
}
