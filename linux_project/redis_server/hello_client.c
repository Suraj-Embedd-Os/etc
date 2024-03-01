#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <arpa/inet.h>
#include<string.h>
#include<stdint.h>

int main()
{
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) 
	{
		perror("socket()");
		return -1;
	}
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = ntohs(1234);
	addr.sin_addr.s_addr = ntohl(INADDR_LOOPBACK); // 127.0.0.1
	int rv = connect(fd, (const struct sockaddr *)&addr, sizeof(addr));
	if (rv) 
	{
		perror("connect");
		return -1;
	}
	while(1)
	{
		int key;
		printf("Enter any key to send or 0 to exit\n");
		scanf("%d",&key);
		if(key ==0)
			break;
		char msg[] = "hello";
		write(fd, msg, strlen(msg));
		char rbuf[64] = {};
		ssize_t n = read(fd, rbuf, sizeof(rbuf) - 1);
		if (n < 0) 
		{
			perror("read");
			return -1;
		}
		printf("server says: %s\n", rbuf);
	
	}
	close(fd);
}