#include <iostream>
#include"array_ADT.h"

using namespace std;




int main()
{
    array<int>a1(10);
    a1.add(4);
    a1.add(10);
    a1.add(14);
    a1.add(140);
    a1.display();
    a1.rotate(2);
    a1.display();
  ;
    return 0;
}


