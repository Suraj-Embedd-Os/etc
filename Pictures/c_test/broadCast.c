#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

	
void boardcast_msg(char *mess){
   int sock;                        
   struct sockaddr_in broadcastAddr; 
   char *broadcastIP;                
   unsigned short broadcastPort;     
   char *sendString;                 
   int broadcastPermission;         
   int sendStringLen;  

	char rcvMsg[100];   

   broadcastIP = "255.255.255.255";  
   broadcastPort = 30303;

   sendString = mess;             /*  string to broadcast */


   if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0){
       //fprintf(stderr, "socket error");
	   printf("socket creation failed \n");
        exit(1);
   }

	printf("socket creation success \n");
   broadcastPermission = 1;
   if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (void *) &broadcastPermission,sizeof(broadcastPermission)) < 0){
       //fprintf(stderr, "setsockopt error");
	   printf("set socket  failed \n");
      exit(1);
   }
  printf("set socket  success \n");
  
   /* Construct local address structure */
   memset(&broadcastAddr, 0, sizeof(broadcastAddr));   
   broadcastAddr.sin_family = AF_INET;                 
   broadcastAddr.sin_addr.s_addr = inet_addr(broadcastIP);
   broadcastAddr.sin_port = htons(broadcastPort);       

   sendStringLen = strlen(sendString);  

        /* Broadcast sendString in datagram to clients */
        if (sendto(sock, sendString, sendStringLen, 0, (struct sockaddr *)&broadcastAddr, sizeof(broadcastAddr)) != sendStringLen){
             printf("send message failed \n");
            exit(1);
        }
	printf("Message Broadcast success  :%s \n\n",	sendString);
	
	printf("wait to recived packet.....");
	memset(&rcvMsg[0],0,100);
	
	if (recv(sock, rcvMsg, 100, 0) <0){
            printf("reciver failed \n");
            exit(1);
        }
		
	printf("Message recived success  :%s \n\n",rcvMsg);
}

int main()
{
	
	char ch ='D';
	boardcast_msg(&ch);
	return 0;
	
}

