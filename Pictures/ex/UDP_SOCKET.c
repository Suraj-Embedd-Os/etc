#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>


#define PORT	    30303

int main()
{
	char SonarIp[]="169.254.28.71";
	int socfd=-1,ret=-1;
	struct sockaddr_in serv,cli;
	char sendCmd='D';
	char recvBuff[100];
	memset(&serv,0,sizeof(serv));
	memset(&cli,0,sizeof(cli));
	memset(recvBuff,0,100);
	
	if((socfd=socket(AF_INET,SOCK_DGRAM,0))<0)
	{
		perror("socket failed");
		return -1;
	}
	printf("SERVER:: socket created\n");
	
	serv.sin_family=AF_INET;
	serv.sin_port=htons(PORT);
	serv.sin_addr.s_addr=inet_addr(SonarIp);
	
	//bind operations
	if((ret=bind(socfd,(struct sockaddr *)&serv,sizeof(serv)))<0)
	{
		perror("Bind failed");
		close(socfd);
		return -1;
	}

	printf("socket binded to %s ::%d \n",inet_ntoa(serv.sin_addr),ntohs(serv.sin_port));
	
	printf("Server is ready to communicate with other...\n");
	
	if((ret= sendto(socfd, (char *)&sendCmd, 1, 0,
           (struct sockaddr *)&serv, sizeof(serv)))<0)
		   {
			  perror("send failed");
			close(socfd);
			return -1; 
		   }
		   
		 int len=sizeof(cli);
		 
		 if((ret= recvfrom(socfd, recvBuff, 100, 0,
             (struct sockaddr *)&cli, &len))<0)
			 {
				 
				perror("recieved failed");
				close(socfd);
				return -1; 
			 }
			 printf("SERVER::msg recieved from %s\n",inet_ntoa(cli.sin_addr));
			 printf("SERVER::msg recieved from client %s\n",recvBuff);
			 
			 
			 close(socfd);
			 printf("server socket closed \n");
	
	return 0;
}