

#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("Usage Error <src zip > <dest usb port>\n");
		return -1;
	}
	
	 int fd = open(argv[1],"rb");
	
	if(fp == NULL)
	{
		perror("FP");
		return -1;
	}
	
	FILE *dest = fopen(argv[2],"wb");
	
	if(dest == NULL)
	{
		perror("dest");
		return -1;
	}
	int c;
	while((c=fgetc(fp)) != EOF)
	{
		fputc(c,dest);
	}
	
	
	return 0;
	
}
