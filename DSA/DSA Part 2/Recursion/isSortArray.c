
#include <stdio.h>

int isSortedArray(int *arr,int n)
{
   if(n==1)
   return 1;
   
  int a=isSortedArray(arr,n-1);
  if(a==0)
  return 0;
  else
  {
      printf("%d is greater than %d \n",arr[n-1],arr[n-2]);
      return arr[n-1]>arr[n-2]?1:0;
  }
   
   
}

int main()
{
    int arr[]={1,2,3,4,5};
    printf("%d ",isSortedArray(arr,5));
    return 0;
}
