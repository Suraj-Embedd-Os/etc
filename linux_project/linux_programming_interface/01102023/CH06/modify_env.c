
#include<stdio.h>
#include<stdlib.h>

extern char **environ;


int 
main(int argc, char *argv[])
{
	int j;
	char **ep;
	
	clearenv();
	
	for(j=1;j<argc;j++)
		if(putenv(argv[j]) !=0){
			printf("putenv %s \n",argv[j]);
			return -1;
		}
		
	if(setenv("GREET","Hello world",0)==-1)
	{
		perror("setenv");
		return -1;
		
	}
	
	unsetenv("BYE");
	
	for(ep=environ;*ep !=NULL;ep++)
		puts(*ep);
	
	return 0;
}
