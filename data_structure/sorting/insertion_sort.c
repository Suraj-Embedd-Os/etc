#include <stdio.h>

void insertionSort(int list[],int low,int high)
{
    for(int h=low;h<=high;h++)
    {
        int key=list[h];
        int k=h-1;
        
        while(k>=low && key<list[k])
        {
            list[k+1]=list[k];
            --k;
        }
        list[k+1]=key;
    }
}

void insertInPlace(int list[],int data,int low,int high)
{
    int k=high;
    while(k>=low && data<list[k])
    {
        list[k+1]=list[k];
        --k;
    }
    list[k+1]=data;
}

int main()
{
   
    int list[10]={4,5,1,32,8,9,10};
    
   insertionSort(list,0,6);
   insertInPlace(list,3,0,6);
    for(int i=0;i<10;i++)
    {
        printf("%d ",list[i]);
    }
    return 0;
}









