#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int agrc,char* argv[])
{


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
                server.sin_addr.s_addr=htonl(INADDR_ANY);//inet_addr("127.0.0.1");;
               /* if(bind(sockfd,  (struct sockaddr *)&server,
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
                printf("server listen\n");*/
				
                int size=sizeof(server);
                if((connct=connect(sockfd, (struct sockaddr *)&server,sizeof(server)))<0)
                {
                        perror("connect():");
                        exit(-1);
                }
                printf("client connected to server\n");
				
				getchar();
				//printf("client wait for recieving\n");
                if((recv(connct, buffer, 100 ,0))<0)
                {
                        perror("recv():");
                        exit(-1);
                }
				printf(" client recive %s:\n",buffer);
                memset(buffer,0,sizeof(buffer));
              

				strcpy(buffer,"Hello from client");
                if((send(connct, buffer, strlen(buffer)+1 ,0))<0)
                {
                        perror("send():");
                        exit(-1);
                }
          

                close(sockfd);

        return 0;
}