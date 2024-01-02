

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <stdlib.h>

typedef int temp_file_handle;

temp_file_handle write_temp_file(char *buffer,size_t lenght)
{
	char temp_filename[]="/tmp/temp_file.txt";
	
	int fd=mkstemp(temp_filename);
	
	if(fd<0)
	{
		perror("mkstemp");
		exit(-1);
	}
	
	
	unlink(temp_filename);
	
	write(fd,&lenght,sizeof(lenght));
	
	write(fd,buffer,lenght);
	
	
	return fd;
}


char * read_temp_file(temp_file_handle temp_file,size_t * lenght)
{
	char *buffer;
	
	int fd=temp_file;
	
	lseek(fd,0,SEEK_SET);
	
	read(fd,lenght,sizeof(*lenght));
	
	buffer=(char*)malloc(*lenght);
	
	read(fd,buffer,*lenght);
	
	close(fd);
	return buffer;
	
}

int main()
{
	char test_file[]="test number";
	int len=strlen(test_file);
	temp_file_handle temp_file = write_temp_file(test_file,len);
	size_t len1=0;
	getchar();
	char *read=read_temp_file(temp_file,&len1);
	
	printf("%s ",read);
	
	return 0;
}
