/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

// minimum index finder

int minIndex(int arr[], int s, int e)
{
	int sml = INT32_MAX;
	int mindex;
	for (int i = s; i < e; i++) {
		if (sml > arr[i]) {
			sml = arr[i];
			mindex = i;
		}
	}
	return mindex;
}

void fun2(int arr[], int start_index, int end_index)
{
	if (start_index >= end_index)
		return;
	int min_index;
	int temp;

	// minIndex() returns index of minimum value in
	// array arr[start_index...end_index]
	min_index = minIndex(arr, start_index, end_index);

	// swap the element at start_index and min_index
	swap(arr[start_index], arr[min_index]);

	fun2(arr, start_index + 1, end_index);
}

// This code is contributed by nishant_0073


int main()
{
    
    int arr[10]={10,2,3,4,500,6,700,80,90,1000};
    
    for(int i=0;i<10;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    
    fun2(arr,0,9);
    
    for(int i=0;i<10;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}























/******************************************************************************

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<iostream>
using namespace std;


void sortArray(int *arr,int startindex,int endex);
int minIndex(int *arr,int startex,int endex);
void swap(int *arr,int m,int n);

int main()
{
     int arr[10]={100,20,3,40,5,60,7,8,90,10};
    
    for(int i=0;i<10;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    
    sortArray(arr,0,9);
    
    cout<<endl;
    
    for(int i=0;i<10;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}


int minIndex(int *arr,int startex,int endex)
{
    int sml=0x7fffffff;
    int minindex;
    
    for(int i=startex;i<=endex;i++)
    {
        if(sml>arr[i])
        {
            sml=arr[i];
            minindex=i;
        }
    }
    //printf("%d ",minindex);
    return minindex;
}

void swap(int *arr,int m,int n)
{
    int temp=arr[m];
   
    arr[m]=arr[n];
    arr[n]=temp;
}


void sortArray(int *arr,int startindex,int endex)
{
    if(startindex>=endex)
    return;
    
    
    int minindex;
    
    minindex=minIndex(arr,startindex,endex);
    
    swap(arr,startindex,minindex);
    
    sortArray(arr,startindex+1,endex);
    
    
}
