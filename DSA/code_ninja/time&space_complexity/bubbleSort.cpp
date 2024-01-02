





#include<iostream>
#include<cstdio>
#include "getTime.h"

using namespace std;


void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}



void bubbleSort(int *arr,int start,int end)
{
	for(int i=start;i<=end;i++)
	{
		for(int j=i+1;j<=end-i;j++)
		{
			if(arr[i]>arr[j])
			{
				swap(&arr[i],&arr[j]);
			}
		}
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
		bubbleSort(arr,0,n-1);
		endTime=getTimeInusec();
		
		//cout<<"selectionSort n = "<<n<<" time in usec "<<endTime-startTim<<endl;
		
		printf("selectionSort n =%d time in usec %lld \n",n,endTime-startTim);
		
	}

	return 0;
}