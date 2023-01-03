

#include<stdio.h>


int gcd1(int ,int );
int gcd2(int ,int );


int main()
{
	int a=10,b=15;
	
	printf("gcd of %d and %d ",a,b,gcd(a,b));
	return 0;
}

int gcd1(int a,int b)
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

int gcd2(int a,int b)
{
    if(a<0 || b <0)
    return -1;
    if(a<b)
    {
        int t=a;
            a=b;
            b=t;
    }
    
   int  r=a%b;
    a=b;
    b=r;
    while(r>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
