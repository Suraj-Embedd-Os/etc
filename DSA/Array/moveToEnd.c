
#include <stdio.h>
int moveZeroEnd_1(int *arr,int arr_size);
int moveZeroEnd_2(int *arr,int arr_size);

int main()
{
    
    int arr[]={1,2,0,5,9,0,9,0,10,98};
    
    moveZeroEnd_2(arr,10);
    
    for(int i=0;i<10;i++)
    printf("%d ",arr[i]);

    return 0;
}

int moveZeroEnd_2(int *arr,int arr_size)
{
	int cnt=0;
	
	for(int i=0;i<arr_size;i++)
	{
	    if(arr[i] != 0)
	    {
	        int t=arr[i];
	        arr[i]=arr[cnt];
	        arr[cnt]=t;
	        cnt++;
	    }
	}
    
}


int moveZeroEnd_1(int *arr,int arr_size)
{
    for(int i=0;i<arr_size;i++)
    {
        if(arr[i]==0)
        {
            for(int j=i+1;j<arr_size;j++)
            {
                if(arr[j] != 0)
                {
                 int t=arr[i];
                 arr[i]=arr[j];
                 arr[j]=t;
                 break;
                }
            }
            
        }
        
    }
}
