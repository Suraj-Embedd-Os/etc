#include <iostream>
#include"Matrix.h"

using namespace std;

/*#define DIAGONAL
#define TRIANGULAR
#define SYMMETRIC*/
#define TRIDIAGONAL

void diagonalMatrixTest();
void triangularMatrixTest();
void symmetricMatrixTest();
void tridiagonalMatrixTest();







int main()
{
    #ifdef DIAGONAL
    diagonalMatrixTest();
    #endif

    #ifdef TRIANGULAR
    triangularMatrixTest();
    #endif

    #ifdef SYMMETRIC
    symmetricMatrixTest();
    #endif // SYMMETRIC

    #ifdef TRIDIAGONAL
    tridiagonalMatrixTest();
    #endif


    return 0;
}

void diagonalMatrixTest()
{
    DiagonalMatrix d1;
    d1.n=4;

    d1.setDiagonal(1,1,4);
    d1.setDiagonal(2,2,4);
    d1.setDiagonal(3,3,4);
    d1.setDiagonal(4,4,40);

    d1.display();
}
void triangularMatrixTest()
{

    TriangularMatrix T1;

    cout<<"Enter size of matrix :";
    cin>>T1.size;

    T1.data = new int[T1.size*(T1.size+1)/2];
    int cnt=1;
    for(int i=1;i<=T1.size;i++)
    {
        for(int j=1;j<=T1.size;j++)
            T1.setMatrix(i,j,cnt++);
    }
    T1.display();

}
void symmetricMatrixTest()
{
    SymmetricMatrix S1;

    cout<<"Enter size of matrix :";
    cin>>S1.size;

    S1.data = new int[S1.size*(S1.size+1)/2];
    int cnt=1;
    for(int i=1;i<=S1.size;i++)
    {
        for(int j=1;j<=S1.size;j++)
            S1.setMatrix(i,j,cnt++);
    }
    S1.display();
}

void tridiagonalMatrixTest()
{
    TridigonalMatrix S1;

    cout<<"Enter size of matrix :";
    cin>>S1.size;

    S1.data = new int[3*S1.size-1];
    int cnt=1;
    for(int i=1;i<=S1.size;i++)
    {
        for(int j=1;j<=S1.size;j++)
            S1.setMatrix(i,j,cnt++);
    }
    S1.display();

}
