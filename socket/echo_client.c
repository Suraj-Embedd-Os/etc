
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

void DieWithError(char *msg)
{
	perror(msg);
	exit(0);
}

int main()
{
	int servSock,clientSock;
		struct sockaddr_in echoServAddr,clntLen;
		if((clientSock= socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
			DieWithError("socket() failed");
		printf("socket create success.....\n");
		
			echoServAddr.sin_family= AF_INET;         /* Internet address family */ 
			echoServAddr.sin_addr.s_addr= htonl(INADDR_ANY);     /* Any incoming interface */ 
			echoServAddr.sin_port= htons(echoServPort);      /* Local port */
			
		
		
			if (connect(clientSock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
			DieWithError("connect() failed");
			
			printf("connect to server ip:%s and port:%d \n",inet_ntoa(echoServAddr.sin_addr),echoServAddr.sin_port);
			
			char buff[100];
			write(fileno(stdout),"\nEnter msg:\n",13);
			read(fileno(stdin),buff,sizeof(buff));
			
			
			send(clientSock, buff, strlen(buff),0);
			memset(buff,0,sizeof(buff));
			recv(clientSock, buff, sizeof(buff),0);
			
			printf("\n");
			write(fileno(stdout),buff,strlen(buff));
			/*for (;;) /* Run forever */ 
			/*{ 
				
				
			}*/
			close(clientSock);
			return 0;
			
}
			
			
			
			
			

 
 