

#include<stdio.h>

int fact(int n)
{
	if(n==0 || n== 1)
		return 1;
	
	int a=n*fact(n-1);
	return a;
	
}

int main()
{
	printf("%d \n",fact(5));
	return 0;
}
