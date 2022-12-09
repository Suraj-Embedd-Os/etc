#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void sig_usr(int);

int main()
{
	 if(signal(SIGUSR1, sig_usr)==SIG_ERR)
	{
		perror("cant cathc SIGUSR1\n");
	}
	
	 if(signal(SIGUSR2, sig_usr)==SIG_ERR)
	{
		perror("cant cathc SIGUSR2\n");
	}
	for(;;)
		pause();
		
	return 0;
}

void sig_usr(int sig_no)
{
	if(sig_no==SIGUSR1)
		printf("Recived SIGUSR1\n");
	else if(sig_no==SIGUSR2)
		printf("Recived SIGUSR2\n");
	else
		printf("Recived sig no %d\n",sig_no);
}








