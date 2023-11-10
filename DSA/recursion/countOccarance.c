
#include <stdio.h>

int countOccarance(int *arr,int arr_size,int n)
{
    if(arr_size==0)
    return 0;
    
   
    
    int a=countOccarance(arr+1,arr_size-1,n);
     
     if(arr[0]==n)
         return a+1;
     else
      return a;

}

int countOccarance(int *arr,int arr_size,int n)
{
    if(arr_size==0)
    return 0;
    
    else if(arr[0]==n)
         return 1+countOccarance(arr+1,arr_size-1,n);
     else
      return countOccarance(arr+1,arr_size-1,n);

}

int main()
{
    int a[]={5,2,3,5,5,5,4,5,7,5};
    printf("%d ",countOccarance(a,10,5));

    return 0;
}
