#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#define MAX 80
#define PORT 8888
#define SA struct sockaddr



int main()
{
	int sockfd,  connfd;
	struct sockaddr_in servaddr, cli;

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
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}
	else
		printf("connected to the server..\n");
	
	    /*pthread_t thread_id;
		
		if(pthread_create(&thread_id, NULL, func,NULL)<0)
		{
			perror("pthread_create()");
			exit(-1);
		}
		pthread_join(thread_id, NULL);*/
	// function for chat
		char buff[100];
		memset(buff,0,100);
		read(sockfd,buff,100);
		printf("server send %s\n",buff);
		
		memset(buff,0,100);
		read(sockfd,buff,100);
		printf("server send %s\n",buff);
		
		write(sockfd,"hii",3);
		
		memset(buff,0,100);
		read(sockfd,buff,100);
		printf("server send %s\n",buff);

	// close the socket
	close(sockfd);
}
