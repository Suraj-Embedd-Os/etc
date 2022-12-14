#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>


void listenForPackets();
void broadCast();
int main()
{
	int pid=fork();

	if(pid>0)
	{
		while(1)
		{
			broadCast();
			sleep(10);
		}
	}
	else if(pid==0)
	{
		while(1)
		{
			listenForPackets();
			sleep(3);
		}
		
	}
	else
		printf("fork faild chile not created\n");
		
	return 0;
}

void broadCast()
{
    int socketSD = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socketSD <= 0) {
       perror("socket failed()");
        return;
    }
    
    // set socket options enable broadcast
    int broadcastEnable = 1;
    int ret = setsockopt(socketSD, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    if (ret) {
         perror("setsockopt failed()");
        close(socketSD);
        return;
    }
    
    // Configure the port and ip we want to send to
    struct sockaddr_in broadcastAddr;
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));
    broadcastAddr.sin_family = AF_INET;
	//inet_pton(AF_INET, "169.254.237.110", &broadcastAddr.sin_addr);
	broadcastAddr.sin_addr.s_addr=inet_addr("255.255.255.255");
    broadcastAddr.sin_port = htons(30303);
    
    char *request = "D";
    ret = sendto(socketSD, request, strlen(request), 0, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr));
    if (ret < 0) {
        perror("sendto failed()");
        close(socketSD);
        return;
    }
	printf("BroadCast To server ip %s  and port::%d\n",inet_ntoa(broadcastAddr.sin_addr),htons(broadcastAddr.sin_port));
    printf("Discovery message sent:: %s\n ",request);
	printf("...........................\n");
	
	
	
    close(socketSD);
    
    
}

void listenForPackets()
{
    int listeningSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (listeningSocket <= 0) {
         perror("socket failed()");
        return;
    }
    
    // set timeout to 2 seconds.
    struct timeval timeV;
    timeV.tv_sec = 2;
    timeV.tv_usec = 0;
    
    if (setsockopt(listeningSocket, SOL_SOCKET, SO_RCVTIMEO, &timeV, sizeof(timeV)) == -1){
         perror("setsockopt failed()");
        close(listeningSocket);
        return;
    }
    
    // bind the port
    struct sockaddr_in sockaddr;
    memset(&sockaddr, 0, sizeof(sockaddr));
    
    //sockaddr.sin_len = sizeof(sockaddr);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(30303);
    sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);//inet_addr("169.254.237.110");//;
    
    int status = bind(listeningSocket, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    if (status == -1) {
        close(listeningSocket);
          perror("setsockopt bind()");
        return;
    }
    
    // receive
    struct sockaddr_in receiveSockaddr;
	memset(&receiveSockaddr,0,sizeof(receiveSockaddr));
    socklen_t receiveSockaddrLen = sizeof(receiveSockaddr);
    
    size_t bufSize = 9216;
    char buf[bufSize];
	memset(buf,'\0',sizeof(buf));
    ssize_t result = recvfrom(listeningSocket, buf, bufSize, 0, (struct sockaddr *)&receiveSockaddr, &receiveSockaddrLen);
   
	printf("Recive from:: %s port::%d\n",inet_ntoa(receiveSockaddr.sin_addr),htons(receiveSockaddr.sin_port));
	printf("RECIVE :: %s \n",buf);
	printf("...........................\n");
		/*
    if (result > 0) {
        if ((size_t)result != bufSize) {
            buf = realloc(buf, result);
        }
        
        char addrBuf[1000];
        if (inet_ntop(AF_INET, &receiveSockaddr.sin_addr, addrBuf, (size_t)sizeof(addrBuf)) == NULL) {
            addrBuf[0] = '\0';
        }
        
        NSString *address = [NSString stringWithCString:addrBuf encoding:NSASCIIStringEncoding];
        NSString *msg = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self didReceiveMessage:msg fromAddress:address];
        });
        
    } else {
       
    }
    */
	
    close(listeningSocket);
}