

int isSorted(int *arr,int size)
{
    if(size==0 || size==1)
    return 1;
    
    if(arr[0]>arr[1])
    return 0;
    
    int s=isSorted(arr+1,size-1);
    return s;
}

int main()
{
    int a[]={1,2,3,4,5};
    printf("%d ",isSorted(a,5));

    return 0;
}



int isSorted(int *arr,int size)
{
    if(size==0 || size==1)
    return 1;
    
    int s=isSorted(arr+1,size-1);
    
    if(!s)
    {
        return 0;
    }
    
    if(arr[0]>arr[1])
    return 0;
    else
    return 1;
    
}

