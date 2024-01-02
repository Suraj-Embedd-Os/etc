
#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<fcntl.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void func(int);

int main()
{
        int sockfd, connfd, len;
        struct sockaddr_in servaddr, cli;

        //socket create and verifictaions
        sockfd = socket(AF_INET,SOCK_DGRAM,0);
        if(sockfd== -1)
        {
                printf("socket create failed ...\n");
                exit(0);
        }
        else
                printf("socket successfully created..\n");

        bzero(&servaddr,sizeof(servaddr));

        //assign IP, PORT
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORT);


 //Connect the socket to server
        if(connect(sockfd,(SA*)&servaddr,sizeof(servaddr)) !=0)
                {
                        printf("connection with server failed...\n");
                        exit(1);
                }
        else
                printf("connected to server..\n");

        //function for chatting between server and client

        func(sockfd);

        close(sockfd);


        return 0;

}

void func(int sockfd)
{
        char buff[MAX];
        int n;

        //infinte loop for chat
        for(;;)
        {
                bzero(buff,MAX);

                printf("Enter the string :");
                n=0;


                while((buff[n++] = getchar()) != '\n');


                write(sockfd,buff,sizeof(buff));
                bzero(buff,MAX);

                read(sockfd,buff,sizeof(buff));
                printf("From server %s : ",buff);
				

                if((strncmp(buff,"exit",4))==0)
                {
                        printf("Client exit..\n");
                        break;
                }

        }

}