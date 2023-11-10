
#include<stdio.h>
#include<unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include<stdlib.h>
 #include<errno.h>
 #include<string.h>
 #include <fcntl.h>


int main()
{
	int fd;;
	int sz;
	
	fd=open("testfile",O_RDONLY);
	
	char buf[100];
	memset(buf,0,100);
	sz=pread(fd,buf,10,0);
	
	printf("%s",buf);
	memset(buf,0,100);
	sz+=pread(fd,buf,10,sz);
	printf("%s",buf);
	memset(buf,0,100);
	sz+=pread(fd,buf,10,sz);
	printf("%s",buf);
	return 0;
}
