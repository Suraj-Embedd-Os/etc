#include <iostream>
#include"Matrix.h"

using namespace std;







int main()
{
    DiagonalMatrix d1;
    d1.n=4;

    d1.setDiagonal(1,1,4);
    d1.setDiagonal(2,2,4);
    d1.setDiagonal(3,3,4);
    d1.setDiagonal(4,4,40);

    d1.display();
    return 0;
}
