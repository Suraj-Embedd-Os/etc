

#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>


int main(int argc,char *argv[])
{
	int opt;
	int inFd;
	int outFd;
	inFd=open(argv[1],O_RDONLY);
	outFd=open(argv[2],O_WRONLY|O_CREAT|O_APPEND);
	
	while((opt=getopt(argc,argv,"abcdef")) !=-1)
	{
		
		
	}
	
	return 0;
	
}
