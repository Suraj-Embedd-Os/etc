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
#define PORT 30303
#define SA struct sockaddr


int main()
{
        struct sockaddr_in servaddr, cliaddr;
        int sockfd;
        char command ='D';
        //socket create and verifictaions
        sockfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
        if(sockfd== -1)
        {
                printf("socket create failed ...\n");
                exit(1);
        }

        memset(&servaddr,0,sizeof(servaddr));

        //assign IP, PORT
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("169.245.28.71");
        servaddr.sin_port = htons(PORT);


        int len = sizeof(servaddr);
        char buff[MAX];


        if(sendto(sockfd,(const char *)&command,sizeof(command),MSG_CONFIRM,&servaddr,len)<0)
		{
			printf("failed to sent \n");
		}
        printf("Message  sent succeefully\n");

		memset(&buff[0],0,MAX);
		
        int n=recvfrom(sockfd,(char *)buff,MAX,MSG_WAITALL,&servaddr,&len);
		       buff[n]='\0';

        printf("message recived: %s\n",buff);

        close(sockfd);
        return 0;

}
