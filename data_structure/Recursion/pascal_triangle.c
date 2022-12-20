/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>

int factorial(int n);
int comb(int n,int r);


int main()
{
    int i,j,k;
    
    printf("Enter no of row for pascal triangle\n");
    scanf("%d",&k);
    system("clear");
    
    for(i=0;i<k;i++)
    {
        for(j=0;j<=i;j++)
        printf("%d ",comb(i,j));
        printf("\n");
    }
    return 0;
}

int comb(int n,int r)
{
    return  factorial(n)/(factorial(r)*factorial(n-r));   
}

int factorial(int n)
{
    if(n==0||n==1)
    return 1;
    else
    return n*factorial(n-1);
}



