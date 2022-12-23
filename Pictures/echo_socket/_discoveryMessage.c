#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>

void broad_Cast(void);

int main()
{

		while(1)
		{
			broad_Cast();
			sleep(12);
		}
	return 0;
}

void broad_Cast(void)
{
	//Create socket descriptor for UDP communication
    int socketSD = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socketSD <= 0) {
       perror("socket failed()");
        return;
    }
    
    // set socket options enable broadcast
    int broadcastEnable = 1;
	int ret=-1;
	
    /*int ret = setsockopt(socketSD, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    if (ret) {
         perror("setsockopt failed()");
        close(socketSD);
        return;
    }*/
    
    // Configure the port and ip we want to send to
    struct sockaddr_in broadcastAddr;
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));
    broadcastAddr.sin_family = AF_INET;
	//inet_pton(AF_INET, "169.254.237.110", &broadcastAddr.sin_addr);
	broadcastAddr.sin_addr.s_addr=inet_addr("192.168.60.211");
    broadcastAddr.sin_port = htons(12345);
    
	
	// bind the port
    struct sockaddr_in sockaddr;
    memset(&sockaddr, 0, sizeof(sockaddr));
   
    //sockaddr.sin_len = sizeof(sockaddr);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(12345);
    sockaddr.sin_addr.s_addr = inet_addr("169.254.237.110");//htonl(INADDR_ANY);//inet_addr("169.254.237.110");//;
    
	// Bind the socket
    int status = bind(socketSD, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    if (status == -1) {
        close(socketSD);
          perror(" bind()");
        return;
    }
	
    char *request = "\r";
	// Send Discovery message
    ret = sendto(socketSD, request, strlen(request), 0, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr));
    if (ret < 0) {
        perror("sendto failed()");
        close(socketSD);
        return;
    }
	printf("BroadCast To server ip %s  and port::%d\n",inet_ntoa(broadcastAddr.sin_addr),htons(broadcastAddr.sin_port));
    printf("Discovery message sent\n");
	printf("...........................\n");
	
	
	//recive data structure
    struct sockaddr_in receiveSockaddr;
	memset(&receiveSockaddr,0,sizeof(receiveSockaddr));
    socklen_t receiveSockaddrLen = sizeof(receiveSockaddr);
    
    size_t bufSize = 9216;
    char buf[bufSize];
	memset(buf,'\0',sizeof(buf));
	
	// receive ip ,device and mac informations
    ssize_t result = recvfrom(socketSD, buf, bufSize, 0, (struct sockaddr *)&receiveSockaddr, &receiveSockaddrLen);
   
   //display ip and port form recived
	printf("Recive from:: %s port::%d\n",inet_ntoa(receiveSockaddr.sin_addr),htons(receiveSockaddr.sin_port));
	printf("RECIVE :: %s \n",buf);
	printf("...........................\n");
	
    close(socketSD);
    
    
}
