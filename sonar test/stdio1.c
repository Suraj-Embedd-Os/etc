#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define MAXLINE 	5
int main()
{
	FILE *fp;
	int c;
	char buf[MAXLINE];
	while(fgets(buf, MAXLINE, stdin) != NULL)
	if (fputs(buf, stdout) == EOF)
	printf("output error\n");
	if (ferror(stdin))
	printf("input error");
	exit(0);
	
		return 0;
}

