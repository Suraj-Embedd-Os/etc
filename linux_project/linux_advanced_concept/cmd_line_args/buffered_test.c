

#include<stdio.h>
#include<unistd.h>

int main()
{
	//printf("hello %d ",BUFSIZ);
	printf("hello ");
	while(1)
	{
		printf(".");
		sleep(1);
	}
	/*while (1) 
	{   
		fprintf (stderr, ".");    
		sleep (1);  
	}*/
	
	return 0;
}




