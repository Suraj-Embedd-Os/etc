





#include<iostream>
#include "getTime.h"

using namespace std;


void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}



void selectionSort(int *arr,int start,int end)
{
	for(int i=start;i<=end-1;i++)
	{
		int min_index=i;
		for(int j=i+1;j<=end;j++)
		{
			if(arr[i]>arr[j])
				min_index=j;
		}
		if(min_index !=i)
		swap(&arr[min_index],&arr[i]);
	}
	
}

int main()
{
	for(int n=10;n<=1000000;n =n*10)
	{
		int *arr=new int[n];
		 long long startTim=0;
		 long long endTime =0;
		
		for(int i=0;i<n ;++i)
		{
			arr[i]=n-i;
		}
		
		startTim=getTimeInusec();
		selectionSort(arr,0,n-1);
		endTime=getTimeInusec();
		
		cout<<"selectionSort n = "<<n<<" time in usec "<<endTime-startTim<<endl;
		
	}

	return 0;
}