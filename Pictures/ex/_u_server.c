// server program for udp connection
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 12345
#define MAXLINE 1000


int main(int argc,char *argv[])
{
	/*if(argc<2)
	{
		printf("run with command");
		exit(-1);
	}*/
	char buffer[MAXLINE];
	char *message = "Hello from server";
	int listenfd, len;
	
	struct sockaddr_in servaddr, cliaddr;
	bzero(&servaddr, sizeof(servaddr));
	memset(buffer,0,sizeof(buffer));
	// Create a UDP Socket
			
	servaddr.sin_addr.s_addr =inet_addr("192.168.60.210");
	servaddr.sin_port = htons(PORT);
	servaddr.sin_family = AF_INET;
	#ifdef TCP
	if((listenfd = socket(AF_INET, SOCK_STREAM, 0))<0)
	{
		perror("socket failed() :");
			exit(-1);
	}
	#else
	if((listenfd = socket(AF_INET, SOCK_DGRAM, 0))<0)
	{
		perror("socket failed() :");
			exit(-1);
	}
	#endif
	// bind server address to socket descriptor
	if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr))<0)
	{
		
		perror("bind failed() :");
			exit(-1);
	}
	#ifdef TCP
	if(listen(listenfd,5)<0)
	{
		
		perror("listen failed() :");
			exit(-1);
	}

	if((connct=accept(sockfd, (struct sockaddr *)&server,&len))<0)
		{
			perror("accept():");
			exit(-1);
		}
		printf("client connected to :: %s %d\n",inet_addr(server.sin_addr.s_addr),htons(server.sin_port));	
	#endif
	// send the response
	if(send(listenfd, message, strlen(message)+1, 0)<0)
		{
			perror("send failed :");
			exit(-1);
		}
		memset(buffer,0,MAXLINE);
	//receive the datagram
	len = sizeof(cliaddr);
	if(recv(listenfd, buffer, sizeof(buffer),0)<0)
	{
		perror("revieved failed :");
		exit(-1);
	}		
	 	puts(buffer);
		
		close(listenfd);
		
}
