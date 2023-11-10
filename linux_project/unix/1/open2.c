#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>

int main()
{

	int ch;
	
	while((ch=getc(stdin)!=EOF))
		if(putc(ch,stdout)==EOF)
		perror("putc()\n");
		
		exit(0);

}

