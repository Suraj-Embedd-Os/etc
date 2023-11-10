// Client side implementation of UDP client-server model
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>

#define PORT	 12345
#define MAXLINE  1024

// Driver code
int main(int argv,char *argc[]){
	
	if(argv!=2)
	{
		printf("Send with Command\n");
		exit(EXIT_FAILURE);
			
	}
	int sockfd;
	char buffer[MAXLINE];
	char *cmd = "\r";//argc[1];
	struct sockaddr_in	 servaddr,cliaddr;

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0 ) {
		perror("socket creation failed\n");
		exit(EXIT_FAILURE);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = inet_addr("192.168.60.211");//INADDR_ANY;
	
	int n, len=sizeof(cliaddr);
	if(connect(sockfd,  (struct sockaddr *)&servaddr,
                   sizeof(servaddr))<0)
				   {
					  perror("connect failed\n");
						exit(EXIT_FAILURE); 
					   
				   }
	
	if(sendto(sockfd, (const char *)cmd, strlen(cmd),
		MSG_CONFIRM, (const struct sockaddr *) &servaddr,
			sizeof(servaddr))<0)
			{
			perror("send failed\n");
			exit(EXIT_FAILURE);
			}
	printf("command send %s to IP::%s port::%d\n",cmd,inet_ntoa(servaddr.sin_addr),htons(servaddr.sin_port));
		
	if((n = recvfrom(sockfd, (char *)buffer, MAXLINE,
				MSG_WAITALL, (struct sockaddr *) &cliaddr,
				&len))<0)
				{
				 perror("send failed\n");
				 exit(EXIT_FAILURE);
				}
	printf("Recived from IP::%s port::%d\n",inet_ntoa(cliaddr.sin_addr),htons(cliaddr.sin_port));
				
	buffer[n] = '\0';
	printf("Read data : %s\n", buffer);

	close(sockfd);
	return 0;
}
