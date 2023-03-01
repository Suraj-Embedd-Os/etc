
#include <stdio.h>

int findOddOccuring(int *arr,int arr_size)
{
    int XOR=0,res1=0,res2=0;
    
    for(int i=0;i<arr_size;i++){XOR ^=arr[i];}
    
    int so=(XOR & (~(XOR-1)));
    
    for(int i=0;i<arr_size;i++)
    {
        if(arr[i] & so )
        res1 ^=arr[i];
        else
        res2 ^=arr[i];
    }
    
    printf("%d %d ",res1,res2);
    
    return 0;
    
}

int main()
{
    
    int arr[]={1,1,2,2,3,3,5,6};
    
    findOddOccuring(arr,sizeof(arr)/sizeof(arr[1]));

    return 0;
}
