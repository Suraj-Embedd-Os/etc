#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<netinet/in.h>
#include<fcntl.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX 1024
#define PORT 8080
#define SA struct sockaddr


int main()
{
        struct sockaddr_in servaddr, cliaddr;
        int sockfd;
        char *hello = "hello from server";
        //socket create and verifictaions
        sockfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
        if(sockfd== -1)
        {
                printf("socket create failed ...\n");
                exit(0);
        }

        memset(&servaddr,0,sizeof(servaddr));
        memset(&cliaddr,0,sizeof(cliaddr));
        //assign IP, PORT
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = INADDR_ANY;
        servaddr.sin_port = htons(PORT);

        if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr))) != 0)
        {
                printf("socket bind failed...\n");
                exit(0);
        }

        int len = sizeof(cliaddr);
        char buff[MAX];


        int n = recvfrom(sockfd,(char *)buff,MAX,MSG_WAITALL,(SA*)&cliaddr,&len);
        buff[n]='\0';

        printf("Client : %s\n",buff);

        sendto(sockfd,(const char *)hello,strlen(hello),MSG_CONFIRM,&cliaddr,len);
        printf("Hello message sent\n");

        return 0;

}
