
#include<stdio.h>

void shortMatrix(int *mat,int tlElement);
void printMatrix(int *mat,int row,int col);
void printPrimaryDiagonal(int *mat,int row,int col);
void printSecondaryDiagonal(int *mat,int row,int col);

int main()
{
    int mat[3][3]={{10,2,30},{40,5,6},{70,8,9}};
    printMatrix((int*)mat,3,3);
    
     shortMatrix((int*)mat,9);
     printMatrix((int*)mat,3,3);
    //printPrimaryDiagonal((int*)mat,3,3);
    //printSecondaryDiagonal((int*)mat,3,3);
    

    return 0;
}

void printMatrix(int *mat,int row,int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			printf("%d ",*(mat+i*col+j));
		printf("\n");
	}
	printf("\n");
}

void printPrimaryDiagonal(int *mat,int row,int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(i==j)
			printf("%d ",*(mat+i*col+j));
			else 
			printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
}

void printSecondaryDiagonal(int *mat,int row,int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if((i+j)==(col-1))
			printf("%d ",*(mat+i*col+j));
			else 
			printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
}

void shortMatrix(int *mat,int tlElement)
{
	for(int i=0;i<tlElement-1;i++)
	{
		for(int j=0;j<tlElement-1-i;j++)
		{
			if(*(mat+j)>*(mat+j+1))
			{
				int temp=*(mat+j);
				*(mat+j)=*(mat+j+1);
				*(mat+j+1)=temp;
			}
		}
	}
}

