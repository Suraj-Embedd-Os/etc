
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void printhelp(char progrnam[]);


int main(int argc,char *argv[])
{
	
	int i,opt,result=0;
	
	if(argc==1)
	{
		printhelp(argv[0]);
		return 1;
	}
	
	while((opt=getopt(argc,argv,"smh"))!=-1)
	{
		switch(opt)
		{
			case 's':
					result=0;
					for(i=2;i<argc;i++)
						result+=atoi(argv[i]);
					break;
			case 'm':
					result=1;
					for(i=2;i<argc;i++)
						result*=atoi(argv[i]);
					break;
			
			case 'h':
				printhelp(argv[0]);
				return 0;
			default:
				printhelp(argv[0]);
				return 1;
		}
		printf("total %d \n",result);
		
	}
		return 0;
}

void printhelp(char progrnam[])
{
	
	
	printf("%s [-s] [-m] integer ...\n", progrnam);
	printf("-s sums all the integers\n" "-m multiplies all the integers\n" 
		"This program takes any number of integer " "values and either add or multiply them.\n"  
		"For example: %s -m 5 5 5\n", progrnam);
	
}