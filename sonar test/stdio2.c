#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define MAXLINE 	5
int main()
{
	FILE *fp;
	char *pfile="01280591.img";
	
	if(fp=fopen(pfile,"r")==NULL)
	{
		perror("fopen\n");
		exit(0);
	}
	char buff[1024];
	
	while(fread(buff,1,1024,fp)!=EOF)
		printf("%s",buff);
	
	
		return 0;
}

