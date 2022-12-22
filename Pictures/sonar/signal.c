
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

static void sigHandler(int sig)
{
	static int count=0;
	if(sig==SIGINT){
	printf(" ouch %d\n",count++);
	return;
	}
	printf("Caught	SIGQUIT	-	that's	all	folks!\n");
}

int main()
{
	
		if(signal(SIGINT,sigHandler)==SIG_ERR)
			perror("signal");
		if(signal(3,sigHandler)==SIG_ERR)
			perror("signal");
	
		for(;;)
			pause();
}