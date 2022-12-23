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
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(PORT);

        if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr))) != 0)
        {
                printf("socket bind failed...\n");
                exit(0);
        }
        else
                printf("socket successfully bind..\n");

        //Now server ready to listen

        if((listen(sockfd,5)) != 0)
        {
                printf("Listen failed..\n");
                exit(1);
        }
        else
                printf("Server listening...\n");

        len = sizeof(cli);

       /* //Accept the date from client and verify
        connfd = accept(sockfd,(SA*)&cli,&len);
        if(connfd < 0)
        {
                printf("server accept failed...\n");
                exit(1);
        }
        else
                printf("server accept the client..\n");
			*/

        //function for chatting between server and client

        func(connfd);

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

                //read message from client
                read(sockfd,buff,sizeof(buff));

                //print buffer which contains the client content
                printf("From cliet %s\t TO client : ",buff);
                bzero(buff,MAX);

                n=0;
                //copy server message in bufer

                while((buff[n++] = getchar()) != '\n');

                        //And send the buffer to client
                        write(sockfd,buff,sizeof(buff));

                        //if msg contain exit:then server exit and end chat
                        if(strncmp("exit",buff,4)==0)
                        {
                                printf("server exit...\n");
                                break;
                        }


        }

}