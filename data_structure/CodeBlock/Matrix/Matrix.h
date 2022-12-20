#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include<iostream>
/*************************DIAGONAL start  MATRIX *******************/
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

/*************************DIAGONAL end  MATRIX *******************/

#endif // MATRIX_H_INCLUDED
