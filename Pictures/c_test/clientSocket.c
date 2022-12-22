
#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<fcntl.h>
#define PORT	8080
#define MAX		400

void func(int sock_d);
int main(int argc,char * argv[]){
	
	int sock_d,conn_d,len;
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
	servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	conn_d =connect(sock_d, (struct sockAddr*)&servAddr, sizeof(servAddr));
	if(conn_d<0){
		printf("connect() faile to connect\n");
		exit(1);
	}
	else
		printf("connect()  sucessufully\n");
	
	func(sock_d);
	
	close(sock_d);
	
	return 0;
	
}

void func(int sock_d){
	
	char buff[MAX];
	int n=0;
	
	for(;;){
		bzero(buff,MAX);
		printf("Enter the string : ");
		n=0;
		
		while((buff[n++]=getchar()) !='\n');
		
		write(sock_d,buff,sizeof(buff));
			bzero(buff,MAX);
		read(sock_d,buff,sizeof(buff));
		
		printf("From server %s : ",buff);
		
		if(strncmp(buff,"exit",4)==0){
			printf("server exit:");
			break;
		}
	}
}