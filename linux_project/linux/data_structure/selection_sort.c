
#include <stdio.h>



int main()
{
    int arr[10]={9,8,6,11,15,13,1,2,20,5};
    
    int i,j=0,smallest=arr[0],indx=0;
		
		while(j<10)
		{
		    smallest=arr[j];
			for(i=j+1;i<10;i++)
			{
				if(arr[i]<smallest)
				{
					smallest=arr[i];
					indx=i;
				}
			}
		
		    	    int temp=arr[j];
					arr[j]=smallest;
					arr[indx]=temp;
			j++;
			indx=j;
		
		}
			for(i=0;i<10;i++)
			printf("%d ",arr[i]);

    return 0;
}
