/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
/*

ARR[M][N][O][P];
index(ARR[i][j][k][l])= *(ARR+(i*N*O*O+j*O*P+k*P+l))
*/

void print(int *ptr,int m,int n,int o,int p)
{
     for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
    for(int k=0;k<4;k++){
    for(int l=0;l<4;l++){
    printf("%d ",*(ptr+i*n*o*p+j*o*p+k*p+l));  
    }
    printf("\n");
    }
    printf("\n");
    }
    printf("\n");
     }
}

int main()
{
    int A[4][4][4][4];
    
    int cnt=0;
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    for(int k=0;k<4;k++)
    for(int l=0;l<4;l++)
    A[i][j][k][l]=++cnt;
    
    //print((int*)A,4,4,4,4);
    
    printf("%d %d",A[1][1][1][1],*(*(*(*(A+1)+1)+1)+1));
    return 0;
}
