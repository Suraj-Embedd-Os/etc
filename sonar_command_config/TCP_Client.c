#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX 80



void recieve_from_encoder(int sockfd)
{
	float length=0.0f;
	char buff[MAX];
	
	write(sockfd,"pulse data",10);
	int n=read(sockfd, buff, sizeof(buff));
	length =atof(buff);
	printf("recived data %s  %f\n",buff,length);
	
	
}



int main()
{
	int sockfd=create_socket_get_rotary_encoder_data();

	// close the socket
	close(sockfd);
}

int create_socket_get_rotary_encoder_data()
{
	
	int sockfd;
	struct sockaddr_in servaddr;

	// socket create and verification
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
		bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);

	// connect the client socket to server socket
	if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}
	else
		printf("connected to the server..\n");

		return sockfd;
}
