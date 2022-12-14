#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


int main(int argc,char *argv[])
{
	
	int fd=open(argv[1],O_WRONLY);
	if(fd !=-1)
	{
		printf("[PID %ld] file \"%s\" already exits\n",(long)getpid(),argv[1]);
		close(fd);
	}
	else {
		if(errno!=ENOENT)
		{
			perror("open \n");
			return -1;
		}
		else
		{
			fd=open(argv[1],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
			
			if(fd==-1)
			{
				perror("open \n");
				return -1;
			}
			printf("[PID %ld] Created file \"%s\" \n",(long)getpid(),argv[1]);
		}
		
	
	}	
		

}