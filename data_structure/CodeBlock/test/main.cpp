#include <iostream>

using namespace std;


int fun(int n)
{
   static int m1=0,m2=1,m3;

   if(n>0)
   {
     m3=m1+m2;
     m1=m2;
     m2=m3;
     cout<<m3<< " ";
     fun(n-1);
   }


}

int main()
{
    cout<<0<<" "<<1<<" ";
    fun(10-2);
    return 0;
}
