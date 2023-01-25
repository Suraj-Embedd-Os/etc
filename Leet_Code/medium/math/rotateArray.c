
#include<stdio.h>
#include<stdlib.h>


void revers(int *nums,int start,int end)
{
    while(start<end)
    {
        int temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        ++start;
        --end;
    }
}

void rotateArrayRight(int *nums,int numsSize,int k)
{
    revers(nums,0,numsSize-1);
    revers(nums,0,k-1);
    revers(nums,k,numsSize-1);
    
}
void rotateRight(int* nums, int numsSize, int k){
    
    rotateArrayRight(nums,numsSize,k%numsSize);

}

void rotateArrayLeft(int *nums,int numsSize,int k)
{
    revers(nums,0,numsSize-1);
    revers(nums,0,numsSize-k-1);
    revers(nums,numsSize-k,numsSize-1);
    
}
void rotateLeft(int* nums, int numsSize, int k){
    
    rotateArrayLeft(nums,numsSize,k%numsSize);

}

int main()
{
    
    int arr1[]={1,2,3,4,5,6,7};
    int arr2[]={1,2,3,4,5,6,7};
    
    rotateRight(arr1,7,3);
    rotateLeft(arr2,7,3);
    
    for(int i=0;i<7;i++)
    printf("%d ",arr1[i]);
    
    printf("\n");
    
    for(int i=0;i<7;i++)
    printf("%d ",arr2[i]);
    
    printf("\n");

    
    
    return 0;
}


