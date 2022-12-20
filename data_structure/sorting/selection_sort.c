#include <stdio.h>


// __attribute__((weak))
/*
typedef use with integer
typedef use in the structure
typedef use with union
typedef use with the array
typedef use with the pointer
typedef use with the function pointer
*/

void selectionSort(int list[],int low,int high)
{
    auto int getSmallest(int[],int,int);
    auto void swap(int[],int,int);
    
    
    for(int h=low;h<high;h++)
    {
        swap(list,h,getSmallest(list, h, high));
    }
    
    /*******************************************************/
    int getSmallest(int list[],int h,int high)
    {
        int s=list[h];
        int smlIndx=h;
        for(int find=h+1;find<=high;find++)
        {
            if(s>list[find])
            {
                s=list[find];
                smlIndx=find;  
            }
        }
        return smlIndx;
    }
        
    
    void swap(int list [],int h,int s)
    {
        int temp=list[h];
        list[h]=list[s];
        list[s]=temp;
    }
    
}



int main()
{
   
    int list[]={4,5,1,32,8,9,10};
    
    selectionSort(list,0,6);
    
    for(int i=0;i<7;i++)
    {
        printf("%d ",list[i]);
    }
    return 0;
}
