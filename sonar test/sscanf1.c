// Example program to demonstrate sprintf()
#include <stdio.h>
int main()
{
	
	char buff[]={"saturday march 10 1995"};
	char day[20],month[20];
	int date,year;
	
	sscanf(buff,"%s %s %d %d",day,month,&date,&year);
	
	printf("%s %s %d %d\n",day,month,date,year);

	return 0;
}
