#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{

	pid_t pid;
	char buff[4096];
	int status;
	
	printf("%%% ");
	
	while(fgets(buff,4096,stdin)!=NULL){
		if(buff[strlen(buff)-1]=='\n')
			buff[strlen(buff)-1]=0;
		
		if((pid=fork())<0)
		perror("fork()\n");
		else if(pid==0)
		{
			execlp(buff,buff,(char*)0);
			perror("coudnt reach\n");
			exit(127);
		}
		
		if((pid=waitpid(pid,&status,0))<0)
			perror("waitpid()\n");
		printf("%%% ");
	}
	
	exit(0);

}

