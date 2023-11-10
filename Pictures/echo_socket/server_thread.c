
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

void *send_msg(void *arg);
void *rcv_msg(void *arg);
int main(int agrc,char* argv[])
{
		
		pthread_t send_t,recv_t;
		char buffer[100];
		int ret=-1;
		int sockfd=socket(AF_INET,SOCK_STREAM,0);
		int connct=-1;
		struct sockaddr_in server;
		
		
		memset(&server,0,sizeof(server));
		memset(buffer,0,sizeof(buffer));
		if(sockfd<0)
		{
			perror("socket():");
			exit(-1);
		}
	
		server.sin_family=AF_INET;
		server.sin_port=htons(8000);
		server.sin_addr.s_addr=INADDR_ANY;//inet_addr("127.0.0.1");
		if(bind(sockfd,  (struct sockaddr *)&server,
                sizeof(server))<0)
				{
					perror("socket():");
					exit(-1);
				}
				
		if(listen( sockfd, 5)<0)
		{
			perror("listen():");
			exit(-1);
		}
		printf("server listen\n");
		int len=sizeof(server);
		for(;;){

		memset(buffer,0,sizeof(buffer));
		if((connct=accept(sockfd, (struct sockaddr *)&server,&len))<0)
		{
			perror("connct():");
			exit(-1);
		}
		
		
		}
		close(sockfd);
	return 0;
}

