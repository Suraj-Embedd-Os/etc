// udp client driver program
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
  
  
#define PORT 	12345
#define MAXLINE 1000
  
// Driver code
int main(int argc,char *argv[])
{   

	/*if(argc<2)
	{
		printf("run with command");
		exit(-1);
	}*/
    char buffer[MAXLINE];
    char *message = "hello from client";
	//char sendCmd='D';
    int sockfd, n;
    struct sockaddr_in servaddr,clientaddr;
     
	 memset(buffer,0,sizeof(buffer));
    // clear servaddr
    bzero(&servaddr, sizeof(servaddr));
	bzero(&clientaddr, sizeof(clientaddr));
	
    servaddr.sin_addr.s_addr = inet_addr("192.168.60.210");
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;
      
    // create datagram socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
      
	  #ifdef TCP
    // connect to server
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("\n Error : Connect Failed \n");
        exit(-1);
    }
	
	printf("connected to %s ::%d \n",inet_ntoa(servaddr.sin_addr),ntohs(servaddr.sin_port));
	#endif
    // request to send datagram
    // no need to specify server address in sendto
    // connect stores the peers IP and port
    int ret=-1;
	int len=sizeof(clientaddr);
	
		
	if((ret=sendto(sockfd, message, strlen(message)+1, 0, (struct sockaddr*)&servaddr, sizeof(servaddr)))<0)
	{
		printf("send failed\n");
		exit(-1);
	}
      
	printf("Command sent %s\n",argv[1]); 
	printf("Wait for response.....\n");
    // waiting for response
	
    if((ret=recvfrom(sockfd, buffer,sizeof(buffer) , 0, (struct sockaddr*)&clientaddr, &len))<0)
	{
		perror("recvfrom()failed:");
		//printf("recived failed failed\n");
		exit(-1);
	}
    puts(buffer);
	

	//printf("recieve from to %s ::%d \n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
    // close the descriptor
    close(sockfd);
}
