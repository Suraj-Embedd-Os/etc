#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include<pthread.h>


#define PORT 8080



#define FALSE 0
#define TRUE  1


int create_socket(int *connfd);
void send_encoder_pulse(int connfd,char *rd_buff);

int main (int argc, char *argv[])
{
	int connfd;
   int sockfd=create_socket(&connfd);
   
   char * myfifo = "/tmp/myfifo";
   int openFifo=-1;
   char read_buff[20]={'\0'};
   openFifo=open(myfifo,O_RDONLY);
   while(1)
   {
	    
	   int n =read(openFifo,read_buff,sizeof(read_buff));
	   /*if(n<0)
	   {
		   printf("unable to  read from pipe \n");
	   }
	   else 
	   {
	   printf("%d bytes read data from pipe %s\n",n,read_buff);
	   }*/
	   send_encoder_pulse(connfd,read_buff);
	   memset(read_buff,0,sizeof(read_buff));
   
   }
   close(openFifo);
   close(sockfd);
   
    return(0);
}

void send_encoder_pulse(int connfd,char *rd_buff)
{	
	char buff[20]={'\0'};
	
	//system("clear");
	//while(1)
	{
		//printf("waiting for client to be read\n");
		read(connfd,buff,sizeof(buff));
		//printf("read from sonar read %s\n",buff);
		if(strncmp(buff,"pulse data",10)==0)
		{
			memset(buff,0,sizeof(buff));
			write(connfd, rd_buff, strlen(rd_buff)+1);
			//printf("sended length pulse data %s \n",rd_buff);

		}
		
	}
	
}


int create_socket(int *connfd)
{
	
	int sockfd, len;
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
	servaddr.sin_addr.s_addr = inet_addr("192.168.60.205") ;//htonl(INADDR_ANY);
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
	if(connfd!=NULL)
	{
		*connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
		if (connfd < 0) {
			printf("server accept failed...\n");
			exit(0);
		}
		else
			printf("server accept the client...\n");
		
	}
		return sockfd;
	
}

