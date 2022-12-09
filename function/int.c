/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdbool.h>

int
main ()
{
  unsigned char a = 0b10000010;
  unsigned char b = 0b01000001;
  int i, j;
  bool flag1 = false, flag2 = false;

  for (i = 0, j = 7; i < j; i++, j--)
    {
      flag1 = false;
      flag2 = false;
      
      if (a & 1 << i)
	    flag1 = true;

      if (a & 1 << j)
	  flag2 = true;

      if (flag1)
	a |= 1 << j;
      else
	a &= ~(1 << j);

      if (flag2)
	a |= 1 << i;
      else
	a &= ~(1 << i);

    }

  printf ("%x %x", a,b);
  return 0;
}


/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<math.h>

int main()
{
    
    int a=101;
    int b=25;
    int c=562;
    
    int cnt[3]={0};
    
    int temp=a;
    while(temp)
    {
        temp/=10;
        cnt[0]++;
    }
    temp=b;
     while(temp)
    {
        temp/=10;
        cnt[1]++;
    }
    
     temp=c;
     while(temp)
    {
        temp/=10;
        cnt[2]++;
    }
    
    
    
    
    int num=a*pow(10,cnt[1]);
        num+=b;
        num *=pow(10,cnt[2]);
        num +=c;
    printf("%d\n",num);

    return 0;
}

