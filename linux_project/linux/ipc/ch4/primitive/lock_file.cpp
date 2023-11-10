#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<iostream>
#include<fcntl.h>
#include<limits.h>

using namespace std;

const int NTRIES=5;
const int SLEEP=5;
const char* LFILE="/tmp/TEST.LCK";

void set(int ac,char *av[],int *n_tries,int *s_time,char **f_name)
{
	static char full_name[PATH_MAX];
	*n_tries=NTRIES;
	*s_time=SLEEP;

	strcpy(full_name,LFILE);

	switch(ac)
	{
		case 4:
			full_name[0]='\0';
			strcpy(full_name,av[3]);
		case 3:
			if((*s_time=atio(av[2]))<=0)
				*s_time=SLEEP;
		case 2:
			if((*n_tries=atoi(av[1]))<=0)
				*n_tries=NTRIES;
		case 1:
			break;
		default:
			cerr<<"Usage "<<av[0]<<"[[tries][sleep][lock]]"<<endl;
			exit(1);
	}
	*f_name=full_name;
}

bool acquire(int numb_tries,int sleep_time,char *file_name)
{
	int fd,count=0;
	
	while((fd=creat(file_name,0)==-1 && erron ==EACCES)
			if(++count<numb_tries)
			sleep(sleep_time);
			else
			return (false);
			close(fd);
		return (bool(fd!=-1));
}

bool release(char *file_name)
{
	return bool(unlink(file_name)==0);
}


		

