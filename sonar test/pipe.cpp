#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>
#include <sys/types.h>
#define MAXSIZ 4096

using namespace std;


int main(int argc,char *argv[])
{
	pid_t pid;
	static char message[MAXSIZ];
	
	int fd[2];

	if(argc!=2)
	{
		cerr<<"Usagge error"<<*argv<<" message";
		cout<<endl;
		return -1;
	}
	
	if(pipe(fd)==-1)
	{
		perror("pipe()\n");
		return -1;
	}
	
	switch(fork())
	{
		case -1:
		cout<<"unable to fork()\n";
		return -1;
		case 0:
		close(fd[0]);
		
		if(write(fd[1],argv[1],strlen(argv[1]))==-1)
		{
			perror("write()\n");
			exit(0);
		}
		cout<<"message write to pipe "<<argv[1]<<endl;
		close(fd[1]);
		default:
		close(fd[1]);
		if(read(fd[0],message,MAXSIZ)==-1)
		{
			perror("read()\n");
			exit(0);
		}
		
		cout<<"message read from pipe "<<message<<endl;
		close(fd[0]);
	}
	
	return 0;
	
}