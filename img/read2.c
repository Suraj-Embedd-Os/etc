#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>

int main()
{
	int fd,n;
	char buff[1022];
	
	while((n=pread(STDIN_FILENO,buff,6,0))>0)
	{
		if(strncmp(buff,"exit",4)==0)
			break;
		if(pwrite(STDIN_FILENO,buff,n,2)!=n)
		{
			perror("write()\n");
			exit(0);
		}
	}	
		if(n<0)
		{
			perror("rread()\n");
		}
	return 0;
}


