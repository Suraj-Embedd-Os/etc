
#include <stdio.h>
#include<stdlib.h>

void mergeSort(int *arr,int start,int end)
{
    if(start>=end)
    return;
    
 int mid=(start+end)/2;
 mergeSort(arr,start,mid);
 mergeSort(arr,mid+1,end);
 
 int len=end-start+1;
 int *temp=NULL;
 if(len != 0)
  temp=(int *)malloc(len*sizeof(int));
 
 int k=0;
 
 int i=start,j=mid+1;

    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
          temp[k++]=arr[i++];  
        }
        else
        temp[k++]=arr[j++]; 
        
    }
    
    while(i<=mid)
    temp[k++]=arr[i++];  
    while(j<=end)
    temp[k++]=arr[j++];
    i=start;
    for(int l=0;l<k;l++)
    {
        arr[i++]=temp[l];
    }
    
    if(temp!=NULL)
    free(temp);
 
}

int main()
{
    int a[10]={5,7,9,1,2,91,14,23,17,10};
    
    mergeSort(a,0,9);
    
    for(int i=0;i<10;i++)
    printf("%d ",a[i]);
    return 0;
}
