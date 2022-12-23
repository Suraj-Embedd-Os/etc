#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include<iostream>
/*************************DIAGONAL start  MATRIX *******************/
/*
Discriptions : if M[i,j] = 0 if i!=j;
No of no-zero-element=n
No of zero-elements =n^2-n
Index(M[i,j])=ARRAY[i-1];
*/
struct DiagonalMatrix
{
    int A[10];
    int n;
    void setDiagonal(int i,int j,int data)
    {
    if(i==j)
        A[i-1]=data;
    }

    int getDiagonal(int i,int j)
    {
    if(i==j)
        return A[i-1];
    else
        return 0;
    }

    void display()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                    std::cout<<A[i-1]<<" ";
                else
                std::cout<<0<<" ";
            }
            std::cout<<std::endl;
        }
    }

};
/*************************DIAGONAL end  MATRIX *******************/

/*************************Triangular start  MATRIX *******************/
/*
Discriptions : if M[i,j] =0 ,if i>j called upper triangular matrix
                         =0 ,if 1<j called lower triangular matrix
No of no-zero-element=n*n(+1)/2 ,1+2+3....n;
No of zero-elements =n^2-n*(n+1)/2=n*(n-1)/2

Index(M[i,j])=ARRAY[i*(i-1)/2+j-1];


*/

struct TriangularMatrix
{
    int *data;
    int size;

    void setMatrix(int i,int j,int _data)
    {
        if(i>=j)
            data[(i*(i-1)/2)+j-1]=_data;
    }

     int getMatrix(int i,int j,int _data)
    {
        if(i>=j)
            return data[(i*(i-1)/2)+j-1];
    }

    void display()
    {
        for(int i=1;i<=size;i++)
        {
            for(int j=1;j<=size;j++)
            {
                if(i>=j)
                    std::cout<<data[(i*(i-1)/2)+j-1]<<" ";
                else
                    std::cout<<0<<" ";
            }
            std::cout<<std::endl;
        }
    }
};
/*************************Triangular end  MATRIX *******************/

/*************************Symmetric start  MATRIX *******************/

/*
Discriptions : if M[i,j]==M[j,i] called symmetric matrix
No of no-zero-element=n*n(+1)/2 ,1+2+3....n;
No of zero-elements =n^2-n*(n+1)/2=n*(n-1)/2

Index(M[i,j])=ARRAY[i*(i-1)/2+j-1];

*/
struct SymmetricMatrix
{
    int *data;
    int size;

    void setMatrix(int i,int j,int _data)
    {
        if(i>=j)
            data[(i*(i-1)/2)+j-1]=_data;
    }

     int getMatrix(int i,int j,int _data)
    {
        if(i>=j)
            return data[(i*(i-1)/2)+j-1];
    }

    void display()
    {
        for(int i=1;i<=size;i++)
        {
            for(int j=1;j<=size;j++)
            {
                //if(i>=j)
                    std::cout<<data[(i*(i-1)/2)+j-1]<<" ";
                //else
                   // std::cout<<<<" ";
            }
            std::cout<<std::endl;
        }
    }
};

/*************************Symmetric end  MATRIX *******************/


/*************************Tridigonal start  MATRIX *******************/

/*
Discriptions : if M[i,j]= |i-j|<=1 no zero element called Tridigonal matrix
No of no-zero-element=3n-1;
No of zero-elements =n^2-3n-1

Index(M[i,j])= if i-j=0 ,n+i-2
                if i-j=1 i-1;
                if i-j=-1 ,2n+i-2

*/
struct TridigonalMatrix
{
    int *data;
    int size;

    void setMatrix(int i,int j,int _data)
    {
        int index=i-j;

        switch(index)
        {
        case 0:
            data[size+i-2]=_data;
            break;
        case 1:
            data[i-1]=_data;
            break;
        case -1:
            data[2*size+i-2]=_data;
            break;
        default:
            break;

        }
    }

     int getMatrix(int i,int j,int _data)
    {
        int index=i-j;

        switch(index)
        {
        case 0:
            return data[size+i-2];
            break;
        case 1:
            return data[size+i-2];
            break;
        case -1:
            return data[size+i-2];
            break;
        default:
            return 0;

        }
    }

    void display()
    {
        for(int i=1;i<=size;i++)
        {
            for(int j=1;j<=size;j++)
            {
                int index=i-j;

        switch(index)
        {
        case 0:
            std::cout<< data[size+i-2]<<" ";
            break;
        case 1:
            std::cout<< data[size+i-2]<<" ";
            break;
        case -1:
            std::cout<< data[size+i-2]<<" ";
            break;
        default:
            std::cout<<0<<" ";
            break;

        }
            }
            std::cout<<std::endl;
        }
    }
};
/*************************Tridigonal end  MATRIX *******************/


#endif // MATRIX_H_INCLUDED
