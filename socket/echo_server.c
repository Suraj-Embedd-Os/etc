
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include<string.h>
#define echoServPort 10000
#define MAXPENDING   5

void DieWithError(char *msg)
{
	perror(msg);
	exit(0);
}

int main()
{
	int servSock,clientSock;
	struct sockaddr_in echoServAddr,echoClntAddr;
		if((servSock= socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
			DieWithError("socket() failed");
		printf("socket create success.....\n");
		
			echoServAddr.sin_family= AF_INET;         /* Internet address family */ 
			echoServAddr.sin_addr.s_addr= htonl(INADDR_ANY);     /* Any incoming interface */ 
			echoServAddr.sin_port= htons(echoServPort);      /* Local port */
			
		if(bind(servSock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0) 
			DieWithError("bind() failed");
			
			printf("bind success.....\n");
		if(listen(servSock, MAXPENDING) < 0) 
			DieWithError("listen() failed");
			printf("start listening.....\n");
			
			int clntLen;
			char buff[100];
			for (;;) /* Run forever */ 
			{ 
				clntLen= sizeof(echoClntAddr);
			
				if ((clientSock=accept(servSock,(struct sockaddr *)&echoClntAddr,&clntLen))<0)
				DieWithError("accept() failed"); 
				
				printf("cilent connected to server ip %s and port %d\n",inet_ntoa(echoServAddr.sin_addr),echoServAddr.sin_port);
				recv(clientSock, buff, sizeof(buff),0);
				
				write(fileno(stdout),buff,strlen(buff));
				send(clientSock, buff, strlen(buff),0);
				memset(buff,0,sizeof(buff));
				
				close(clientSock);
			}
			close(servSock);
			return 0;
			
}
			
			
			
			
			

 
 