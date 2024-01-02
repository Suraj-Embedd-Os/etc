#include <stdio.h>

int hcd(int a,int b)
{
    int t;
    a>b?(t=a,a=b,b=t):1;
    if(b==0)
    return a;
    else
    return(b,a%b);
}

int findLcm(int *arr,int size)
{
    int res=arr[0];
    
   // printf("%d ",res);
    for(int i=1;i<size;i++)
    {
        res = (res*arr[i])/(hcd(res,arr[i]));
    }
    
    return res;
}

int main()
{
    
    int arr[]={2,3,4,5,6};
    
    printf("%d ",findLcm(arr,5));

    return 0;
}
