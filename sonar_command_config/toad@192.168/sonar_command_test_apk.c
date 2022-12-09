#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<math.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<errno.h>


int profile_survey(unsigned char * cmd,int cmd_len,char *rd_buff,int _size)
{
	printf("cmd get %s\n",cmd);
	
	//Create socket descriptor for UDP communication
    int socketSD = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socketSD <= 0) {
       perror("socket failed()");
        exit(-1);
    }
    
    // set socket options enable broadcast
    int broadcastEnable = 1;
    int ret = setsockopt(socketSD, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    if (ret) {
         perror("setsockopt failed()");
        close(socketSD);
        exit(-1);
    }
    
  
	
	// bind the port
    struct sockaddr_in sockaddr;
    memset(&sockaddr, 0, sizeof(sockaddr));
   
    //sockaddr.sin_len = sizeof(sockaddr);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(12345);
    sockaddr.sin_addr.s_addr = inet_addr("192.168.60.209"); //inet_addr("192.168.60.99");   
	// Bind the socket
    int status = bind(socketSD, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    if (status == -1) {
        close(socketSD);
          perror(" bind()");
        exit(-1);
    }
	
    struct sockaddr_in broadcastAddr;
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));
    broadcastAddr.sin_family = AF_INET;
	
	printf("ethernet ip::%s sonar ip::%s\n","192.168.60.209","192.168.60.211");
    broadcastAddr.sin_addr.s_addr=inet_addr("192.168.60.211");//inet_addr("192.168.60.211");
    broadcastAddr.sin_port = htons(12345);

    unsigned char *request = cmd;
	// Send command message
	 ret = sendto(socketSD, (char *)request, cmd_len+1, 0, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr));
    if (ret < 0) {
        perror("sendto failed()");
        close(socketSD);
        exit(-1);
    }
	printf("send command to server ip %s  and port::%d\n",inet_ntoa(broadcastAddr.sin_addr),htons(broadcastAddr.sin_port));
    printf("command sent\n");
	//printf("...........................\n");
	
	
	//recive data structure
    struct sockaddr_in receiveSockaddr;
	memset(&receiveSockaddr,0,sizeof(receiveSockaddr));
    socklen_t receiveSockaddrLen = sizeof(receiveSockaddr);
    
   
	
	// receive ip ,device and mac informations
    ssize_t result = recvfrom(socketSD, rd_buff,  _size, 0, (struct sockaddr *)&receiveSockaddr, &receiveSockaddrLen);
   
   //display ip and port form recived
	printf("Recive from:: %s port::%d\n",inet_ntoa(receiveSockaddr.sin_addr),htons(receiveSockaddr.sin_port));
	 printf(" RECIVE :: %s \n",rd_buff);
	//printf("...........................\n");

	// To read array of bytes of sweep data 
	if(strncmp(cmd,"W",1)==0)
		{
			//printf(" RECIVE :: %s \n",rd_buff);
			memset(rd_buff,'\0',_size);
			recvfrom(socketSD, rd_buff, _size, 0, (struct sockaddr *)&receiveSockaddr, &receiveSockaddrLen);
			/*int i=0;
			while(rd_buff[i]!='\r')
				printf("%hhu\n",rd_buff[i++]);*/
		}
	 close(socketSD); 
	 return 0; 
}




int main()
{
		
		char cmd[10]={'\0'};
		char rd_buff[100]={'\0'};
		int os=1;
		
		cmd[0]='X';
		cmd[1]=(char)os;
		
		profile_survey(cmd,5,rd_buff,100);
		
		if(!strncmp((char *)&rd_buff,(char *)&cmd,1)){
				printf("set oversamples sucessfull\n");
		}
		else
		{
			printf("failed to set oversamples \n");
		}
		
		printf("................\n");
		memset(rd_buff,0,100);
		
		while(1)
		{
			printf("try again eneter val cmd \n");
			scanf("%d",&os);
			cmd[1]=(char)os;
			profile_survey(cmd,5,rd_buff,100);
			if(!strncmp((char *)&rd_buff,(char *)&cmd,1))
			{
				printf("set oversamples sucessfull\n");
			}
			else
			{
				printf("failed to set oversamples \n");
			}
			
		}
		
		

}