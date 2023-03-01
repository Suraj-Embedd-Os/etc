
#include <stdio.h>
#include<string.h>
#include<math.h>

/*
    XOR properties
XOR is commutative.

This means, a^b = b^a.
XOR is associative.

This means, a^(b^c) = (a^b)^c = (a^c)^b.
XOR is self-inverse.

This means, any number XOR’ed with itself evaluates to 0.

a^a = 0.

0 is the identity element for XOR.

This means, any number XOR’ed with 0 remains unchanged.
a^0 = a.

*/

int findOddOcuuring(int *arr,int arr_size)
{
    int num=0;
    for(int i=0;i<arr_size;i++)
    {
        num ^=arr[i];
        printf("%d ",num);
   
    }
    
    return num;
}

int main()
{
    int arr[]={2,2,3,3,5};
    
    printf("\n%d ",findOddOcuuring(arr,5));
    
    return 0;
}
