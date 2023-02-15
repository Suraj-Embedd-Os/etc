

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>


char ip_add[20];

void handler (int num)
{
	 if(num==SIGINT)
	 {
		 printf("CTRL+c detected \n");
		 char ping_test[30];
		 memset(ping_test,0,30);
		 sprintf(ping_test,"ping -c1 -w1 %s",ip_add);
		 int return_status=system(ping_test);
		 printf("status %d ",return_status);
		 
		 if(return_status==0)
		 exit(0);
	 }
}

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Usage Erorr<IP ADD>\n");
		exit(-1);
	}		
	strcpy(ip_add,argv[1]);
	printf("Ip address is %s \n",ip_add);
	
	signal(SIGINT,handler);
	while(1)
	{
		printf("testing ping application of id address %s \n",argv[1]);
		//sleep(2);
		
	}

	return 0;
}


