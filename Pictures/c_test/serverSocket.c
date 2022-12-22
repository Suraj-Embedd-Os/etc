#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netdb.h>
#include<fcntl.h>
#define PORT	8080
#define MAX		400

void func(int sock_d);
int main(int argc,char * argv[]){
	
	int sock_d,New_conn,len;
	struct sockaddr_in servAddr,cliAddr;
	
	sock_d=socket(AF_INET,SOCK_STREAM,0);
	if(sock_d<0){
		printf("socket() creation failed\n");
		exit(1);
	}
	else
		printf("socket() crete sucessufully\n");
	
	bzero(&cliAddr,sizeof(cliAddr));
	bzero(&servAddr,sizeof(servAddr));
	
	servAddr.sin_family=AF_INET;
	servAddr.sin_port=htons(PORT);
	servAddr. sin_addr.s_addr=htonl(INADDR_ANY);
	
	if(bind(sock_d, (struct sockaddr *)&servAddr, sizeof(servAddr))!=0){
		printf("bind() failed\n");
		exit(1);
	}
	else
		printf("bind()  successufully\n");
	
	if(listen(sock_d,5)!=0){
		printf("listen() failed\n");
		exit(1);
	}
	else
			printf("listen()...........\n");
		
		len=sizeof(cliAddr);
		
	 New_conn=accept( sock_d, (struct sockaddr *)&cliAddr, &len);
	 
	 if(New_conn<0){
		 printf("accept() failed to connect\n");
		 exit(1);
	 }
	 else
		 printf("server accept the client\n");

		
	
	func(New_conn);
	
	close(sock_d);
	
	return 0;
	
}
void func(int sock_d){
	
	char buff[MAX];
	int n=0;
	
	for(;;){
		bzero(buff,MAX);
		read(sock_d,buff,sizeof(buff));
		
		printf("from client %s :\t To Client : ",buff);
		bzero(buff,MAX);
		n=0;
		
		while((buff[n++]=getchar())!='\n');
		
		write(sock_d,buff,sizeof(buff));
		
		if(strncmp(buff,"exit",4)==0){
			printf("client exit:");
			break;
		}
	 
	}
}