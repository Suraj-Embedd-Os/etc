
#include <stdio.h>



int main()
{
    int arr[10]={9,8,6,11,15,13,1,2,20,5};
    
    int i,j=10;
    
    while(j!=0)
    {
        for(i=0;i<j-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        //printf("%d ",arr[i]);
        j--;
    }    
     for(i=0;i<10;i++)
     //printf("%d ",arr[i]);
    return 0;
}
