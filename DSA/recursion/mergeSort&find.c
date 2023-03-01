
#include <stdio.h>
#include<stdlib.h>


void mergeSort(int *arr,int start, int end)
{
    if(start>=end)
    return;
    
    int mid=(start+end)/2;
    
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    
    int len=end-start+1;
    
    int *temp=(int *)malloc(len*sizeof(int));
    
    int i=start,j=mid+1,k=0;
    
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        temp[k++]=arr[i++];
        else
        temp[k++]=arr[j++];
    }
    
      while(i<=mid)
      temp[k++]=arr[i++];
       
    
      while(j<=end)
      temp[k++]=arr[j++];
      
      i=start;
      k=0;
      
      for(;i<=end;i++)
      arr[i]=temp[k++];
      
      free(temp);
    
    

}

int findNum(int *arr,int key,int start,int end)
{
    
    if(start>end)
    return -1;
    
    int mid=(start+end)/2;
    
    printf("%d %d %d \n",start,end,mid);
    
    if(key==arr[mid])
    return key;
    else if(key>arr[mid])
    return findNum(arr,key,mid+1,end);
    else if(key<arr[mid])
    return findNum(arr,key,start,mid-1);
    

}

int main()
{
   int a[]={14,45,80,9,140,245,117,657,798,147};
   
   mergeSort(a,0,sizeof(a)/sizeof(a[0])-1);
   
   
   for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
   printf("%d ",a[i]);
   printf("\n");
   
   printf("\n%d ",findNum(a,9,0,sizeof(a)/sizeof(a[0])-1));

    return 0;
}
