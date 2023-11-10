#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include <sys/types.h>
#include <fcntl.h>

void profile_survey(unsigned char * cmd);

int main(int argc,char* argv[])
{
	
	unsigned char send_cmd[10]={'\0'};
	
	select_options();
	if(argc==1)
	{
		//
		send_cmd[0]= '\r';
		profile_survey(send_cmd);
	}else if(argc==2)
	{
		profile_survey(argv[1]);
	}
	else if(argc==3)
	{
		unsigned short int _temp=0;
		_temp=atoi(argv[2]);
		
		if(_temp<256)
		{
		strncpy(send_cmd,argv[1],1);
	    send_cmd[1]= (_temp & 0xFF);
		}
		else
		{
		strncpy(send_cmd,argv[1],1);
		send_cmd[1]=((_temp>>8)& 0xFF);
	    send_cmd[2]= (_temp & 0xFF);
		}
		profile_survey(send_cmd);
	  
	}
	else
		printf("invalid number of argument\n");
	return 0;
}

void profile_survey(unsigned char * cmd)
{
	//Create socket descriptor for UDP communication
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
	
    broadcastAddr.sin_addr.s_addr=inet_addr("192.169.60,211");
    broadcastAddr.sin_port = htons(12345);
    
	
	// bind the port
    struct sockaddr_in sockaddr;
    memset(&sockaddr, 0, sizeof(sockaddr));
   
    //sockaddr.sin_len = sizeof(sockaddr);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(12345);
    sockaddr.sin_addr.s_addr = inet_addr("169.254.237.110");   
	// Bind the socket
    int status = bind(socketSD, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    if (status == -1) {
        close(socketSD);
          perror(" bind()");
        return;
    }
	
    unsigned char *request = cmd;
	// Send Discovery message
    ret = sendto(socketSD, (char *)request, strlen(request), 0, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr));
    if (ret < 0) {
        perror("sendto failed()");
        close(socketSD);
        return;
    }
	printf("Broadcast to server ip %s  and port::%d\n",inet_ntoa(broadcastAddr.sin_addr),htons(broadcastAddr.sin_port));
    	printf("command sent\n");
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
	printf(" RECIVE :: %s \n",buf);
	printf("...........................\n");

	if(strncmp(cmd,"W",1)==0)
	{
	 memset(buf,'\0',sizeof(buf));
 	 recvfrom(socketSD, buf, bufSize, 0, (struct sockaddr *)&receiveSockaddr, &receiveSockaddrLen);
   
   //display ip and port form recived
	printf("Recive from:: %s port::%d\n",inet_ntoa(receiveSockaddr.sin_addr),htons(receiveSockaddr.sin_port));
		if(buf!=0)
		{
			int i=0;
			while(buf[i]!='\r')
			printf(" %d.data : %hhu \n",i,buf[i++]);
			printf("...........................\n");
		
			FILE *fd=fopen("data.txt","w");
			
			if(fd==0)
			{
				perror("open()");
			}
			else
			{
				i=0;
				while(buf[i++]!='\r')
				fprintf(fd,"%hhu\n",buf[i]);
				fclose(fd);
			}
		}
	}
	
    close(socketSD);
    
    
}

