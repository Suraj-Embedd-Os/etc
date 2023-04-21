





#include<iostream>
#include "getTime.h"

using namespace std;


void insertionSort(int *arr,int start,int end)
{
	for(int i=start+1;i<=end;i++)
	{
		int j=i;
		int key=arr[i];
		
		while(j>=0 && key<arr[j-1])
		{
			arr[j]=arr[j-1];
			j--;
			
		}
		arr[j]=key;
	}
	
	
}

int main()
{
    
    FILE *fp =fopen("export_insertionSort.csv","w");
    fprintf(fp,"Data,Time\n");
    
	for(int n=10;n<=10000;n =n*10)
	{
		int *arr=new int[n];
		 uint64_t startTim=0;
		 uint64_t endTime =0;
		
		for(int i=0;i<n ;++i)
		{
			arr[i]=n-i;
		}
		
		startTim=getTimeInusec();
		insertionSort(arr,0,n-1);
		endTime=getTimeInusec();
		
		cout<<"insertionSort n = "<<n<<" time in usec "<<endTime-startTim<<endl;
		
		fprintf(fp,"%d,%llu\n",n,endTime-startTim);
		
	}
	
	fclose(fp);

	return 0;
}