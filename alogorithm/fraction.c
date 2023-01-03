/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int gcd(int ,int );
struct fraction
{
    int numerator;
    int denomiinator;
};

int main()
{
  struct fraction f1;
  f1.numerator=2048;
  f1.denomiinator=100;
   f1.numerator/=gcd(f1.numerator,f1.denomiinator);
   f1.denomiinator/=gcd(f1.numerator,f1.denomiinator);

   printf("%d %d",f1.numerator,f1.denomiinator);

    return 0;
}

int gcd(int a,int b)
{
	if(a< 0 || b <0)
		return -1;
	
	while(a>0)
	{	
		if(a<b)
		{
			int t=a;
			a=b;
			b=t;
		}
		a=a-b; //20-5=15-5=10-5=5-5=0
	}
	return b;
}

