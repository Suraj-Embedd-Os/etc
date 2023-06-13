
#include <stdio.h>

int maxElement(int *arr,int n)
{
   if(n==1)
   return arr[n-1];
   
   int max=maxElement(arr,n-1);
   
   return max>arr[n-1]?max:arr[n-1];
   
}

int main()
{
    int arr[]={1,2,30,4,5,6};
    printf("%d ",maxElement(arr,6));
    return 0;
}
