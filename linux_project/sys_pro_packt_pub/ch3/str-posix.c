/*#define _XOPEN_SOURCE 700*/

#include<stdio.h>
#include<string.h>



int main()
{
	char a[]="hello";
	
	char *b;
	
	b=strdup(a);
	
	printf("b=%s\n",b);
	
	
	return 0;
	
}

