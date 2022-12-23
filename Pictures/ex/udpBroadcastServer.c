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
	
	char recvBuff[100];
	char sendBuff[100];
	memset(&server,0,sizeof(server));
	memset(&client,0,sizeof(client));
	memset(recvBuff,0,100);
	memset(sendBuff,0,100);
	
	if((socfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP))<0)
	{
		perror("socket failed()");
		return -1;
	}
	printf("SERVER:: socket created\n");
	
	server.sin_family=AF_INET;
	server.sin_port=htons(30303);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	//bind operations
	if((ret=bind(socfd,(struct sockaddr *)&server,sizeof(server)))<0)
	{
		perror("Bind failed()");
		close(socfd);
		return -1;
	}
	printf("socket binded to %s ::%hd \n",inet_ntoa(server.sin_addr),ntohs(server.sin_port));
	
	printf("Server is ready to communicate with other...\n");
	printf(".............................................\n");
	 int len=sizeof(client);
	 
	    
	 
	if(recvfrom(socfd, recvBuff, sizeof(recvBuff),0,(struct sockaddr*)&client,&len)<0)
		   {
			  perror("READ failed():");
				close(socfd);
				return -1; 
		   }
		   printf("SERVER::msg recieved from client:: %s\n",recvBuff);
		 // printf("SERVER::msg recieved from %s\n",inet_ntoa(cli.sin_addr));
			 
		
		client.sin_family=AF_INET;
		client.sin_port=htons(1000);
		client.sin_addr.s_addr=inet_addr("127.0.0.1");
		printf("Enter to messgae to send client.\n");
		gets(sendBuff);

		printf("%s ..\n",sendBuff);
		 if(sendto(socfd, sendBuff, sizeof(sendBuff),0,(struct sockaddr*)&client,sizeof(client))<0)
			 {
				 
				perror("send failed():");
				close(socfd);
				return -1; 
			 }
		
	 
	close(socfd);
	 printf("server socket closed \n");
	return 0;
}
