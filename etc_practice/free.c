

#include<stdio.h>
#include<stdlib.h>


int main()
{
	
	char *p=(char*)malloc(6*sizeof(char));
	
	for(int i=0;i<6;i++)
	{
		p[i]='A'+i;
	}
	
	char *p2=p+10;
	
	printf("%hd ",*((short int*)p2));
	
}
