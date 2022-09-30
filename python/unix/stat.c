#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>


int
main(int argc,char *argv[])
{
	int i;
	struct stat buf;
	char *ptr;
	
	 for(int i=1;i<argc;i++)
	 {
		 printf("%s: ",argv[i]);
		 
		if(lstat(argv[i], &buf)<0)
		{
			perror(argv[i]);
			continue;
		}
	 
	 
	 if(S_ISREG(buf.st_mode))
		 ptr="regular";
	 else if(S_ISBLK(buf.st_mode))
		 ptr="block";
	  else if(S_ISCHR(buf.st_mode))
		 ptr="character";
	  else if(S_ISLNK(buf.st_mode))
		 ptr="link";
	  else if(S_ISSOCK(buf.st_mode))
		 ptr="socket";
	  else if(S_ISFIFO(buf.st_mode))
		 ptr="pipe";
	  else if(S_ISDIR(buf.st_mode))
		 ptr="Directory";
	  else 
		 ptr="...unknown...";
		printf("%s\n",ptr);
	 }
	 
	return 0;
	
}


