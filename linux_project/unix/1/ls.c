#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>


int main(int argc,char *argv[])
{
	 DIR 			*dp;
	 struct dirent  *dir;
	 
	 if((dp=opendir(argv[1]))==NULL)
	 {
		 perror("opendir()\n");
		 exit(0);
	 }
	 printf("Inodenumber 		offset	 size	Type filename\n"); 
	 while((dir=readdir(dp))!=NULL)
	 {
		 printf("%ld\t%ld\t%hu\t%hhu\t%s\n",dir->d_ino,dir->d_off,dir->d_reclen,\
		 dir->d_type,dir->d_name); 
	 }
	 
	 closedir(dp);
	return 0;
}


