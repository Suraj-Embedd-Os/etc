#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<pthread.h>
#define PORT 8080
#define SA struct sockaddr

int create_socket(pthread_t *id);

// Function designed for chat between client and server.
void *send_encoder_pulse(void *args)
{
	int connfd =*(int*)args;
	printf("%d connfd\n",connfd);
	
	float lenght=500.45;
	char buff[100];
	while(1)
	{
		printf("waiting for reading \n");
		read(connfd,buff,sizeof(buff));
		if(strncmp(buff,"pulse data",10)==0)
		{
			sprintf(buff,"%f",lenght);
			write(connfd, buff, sizeof(buff));
			printf("sended pulse data\n");

		}
	}

}

// Driver function
int main()
{
	pthread_t thread_id;
	
		
	int sockfd=create_socket(&thread_id);

	// Wait for join thread
	pthread_join(thread_id, NULL);

	// After chatting close the socket
	close(sockfd);
}

int create_socket(pthread_t *id)
{
	
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;
	
	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	memset(&servaddr, 0,sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1") ;//htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
	if (connfd < 0) {
		printf("server accept failed...\n");
		exit(0);
	}
	else
		printf("server accept the client...\n");
		
	
		
	if(pthread_create(id, NULL, send_encoder_pulse,(void*)&connfd)<0)
		{
			perror("pthread_create()");
			exit(-1);
		}
		
		return sockfd;
	
}
