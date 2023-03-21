





#include<iostream>
#include "getTime.h"

using namespace std;

void merge(int *arr,int start,int mid,int end)
{
	int len=end-start+1;
	
	int *temp= new int[len];
	
	if(temp == NULL)
	{
		cout<<"unable to create "<<endl;
		return ;
	}
	
	int k=0,i=0,j=mid+1;
	
	while(i<=mid && j <=end)
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
	
	for(;i<=end;i++)
		arr[i]=temp[i];
	
	delete [] temp;

}	

void mergesort(int *arr,int start,int end)
{
	if(start>=end)
	{
		return ;
	}
	int mid=(start+end)/2;
	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);
	
}

int main()
{
	for(int n=10;n<=1000000;n =n*10)
	{
		int *arr=new int[n];
		long startTim=0;
		long endTime =0;
		
		for(int i=0;i<n ;++i)
		{
			arr[i]=n-i;
		}
		
		startTim=getTimeInusec();
		mergesort(arr,0,n-1);
		endTime=getTimeInusec();
		
		cout<<"mergesort n = "<<n<<" time in usec "<<endTime-startTim<<endl;
		
	}

	return 0;
}