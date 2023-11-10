#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>


int main()
{

	int fd,n;
	char *path="/tmp/myfifo";
	
	mknod(path,S_IFIFO|0666,0);
	
	fd=open(path,O_RDWR);
	if(fd<0)
	{
		perror("open\n");
		return -1;
	}
	
	char buff[1024];
	while(1)
	{
		memset(buff,0,1024);
		write(fileno(stdout),"\nwrite string:",15);
		fflush(stdout);
		fgets(buff,1024,stdin);
		if(!strncmp("quit",buff,4))
		break;
		write(fd,buff,strlen(buff)+1);
		printf("\nrite sucessfuly\n");
		memset(buff,0,1024);
		read(fd,buff,1024);
		printf("\nread sucessfuly\n");
		write(fileno(stdout),buff,strlen(buff)+1);
		
	}
	close(fd);
}
		
	
