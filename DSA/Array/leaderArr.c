
#include <stdio.h>
int leaderArr_1(int *arr,int arr_size);
int leaderArr_2(int *arr,int arr_size);

int main()
{
    
    int arr[]={1,2,10,9,87,14,46,14,69,5};
    
    leaderArr_1(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n");
    leaderArr_2(arr,sizeof(arr)/sizeof(arr[0]));
    
    

    return 0;
}

int leaderArr_1(int *arr,int arr_size)
{
    int c=0;
	for(int i=0;i<arr_size;i++)
	{
	    c=0;
	    for(int j=i+1;j<arr_size;j++)
	    {
	        if(arr[i]<arr[j])
	        {
	            c=1;
	            break;
	        }
	    }
	    if(!c)
	    printf("%d ",arr[i]);
	    
	}
    
}


int leaderArr_2(int *arr,int arr_size)
{
    int cntLead=arr[arr_size-1];
    printf("%d ",cntLead);
    for(int i=arr_size-2;i>=0;i--)
    {
        if(arr[i]>cntLead) 
        {
            cntLead=arr[i];
            printf("%d ",cntLead);
        }
    }
        
}
