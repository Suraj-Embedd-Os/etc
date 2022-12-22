#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>


int main()
{
	
	int socfd=-1,ret=-1;
	struct sockaddr_in server,client;
	
	char recvBuff[250];
	char sendBuff[100];
	memset(&server,0,sizeof(server));
	memset(&client,0,sizeof(client));
	memset(recvBuff,0,250);
	memset(sendBuff,0,100);
	
	if((socfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP))<0)
	{
		perror("socket failed()");
		return -1;
	}
	printf("SERVER:: socket created\n");
	
	client.sin_family=AF_INET;
	client.sin_port=htons(30303);
	client.sin_addr.s_addr=inet_addr("192.168.60.210"); //INADDR_ANY
	
	//bind operations
	if((ret=bind(socfd,(struct sockaddr *)&client,sizeof(client)))<0)
	{
		perror("Bind failed()");
		close(socfd);
		return -1;
	}
	printf("socket binded to %s ::%d \n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
	
	printf("Server is ready to communicate with other...\n");
	printf(".............................................\n");
	 
	int len=sizeof(client);
	 
	 
	server.sin_family=AF_INET;
	server.sin_port=htons(30303);
	server.sin_addr.s_addr=inet_addr("169.254.237.110");
	
	int broadcast=1;
	if (setsockopt(socfd,SOL_SOCKET,SO_BROADCAST,
		(void*)&broadcast,sizeof(broadcast))==-1) {
			perror("setsockopt failed():");
				close(socfd);
				return -1; 
		}
	
	if (connect(socfd,(struct sockaddr*)&server,sizeof(server))==-1) {
			perror("connect failed():");
				close(socfd);
				return -1; ;
	}
	
	printf("Enter BroadCast Message.\n");
	fgets(sendBuff,sizeof(sendBuff),stdin);
	int i;
	for(i=0;i<65;i++)
	{
	if(sendto(socfd, sendBuff, sizeof(sendBuff),0,(struct sockaddr*)&server,sizeof(server))<0){
			  perror("send failed():");
				close(socfd);
				return -1; 
		}
	}	  
	printf("wait to recieved.\n");	
	
	if(recvfrom(socfd, recvBuff, sizeof(recvBuff),MSG_WAITALL ,(struct sockaddr*)&client,&len)<0)
		{
				 
				perror("read failed():");
				close(socfd);
				return -1; 
		}
			 
		printf("SERVER::msg recieved from %s :: %d \n",inet_ntoa(client.sin_addr),htons(client.sin_port));
		printf("CLIENT::msg recieved from server %s\n",recvBuff);
	 
	close(socfd);
	 printf("client socket closed \n");
	return 0;
}