

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <arpa/inet.h>
#include<string.h>
#include<stdint.h>

const size_t k_max_msg = 4096;

static int32_t one_request(int connfd);
static int read_full(int fd,char *buf,size_t size n);
static int32_t write_all(int fd, const char *buf, size_t n) ;
int main()
{
	
	
	int fd = socket(AF_INET, SOCK_STREAM, 0);
					  
	int val = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
	
	struct sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = ntohs(1234);
	addr.sin_addr.s_addr = ntohl(0); // wildcard address 0.0.0.0
	int rv = bind(fd, (const sockaddr *)&addr, sizeof(addr));
	
	if(rv)
	{
		perror("bind () ");
		return -1;	
	}
	
	
	rv=listen(fd,5);
	
	if(rv<0)
	{
		perror("listen () ");
		return -1;	
			
	}
	
	while(1)
	{
		struct sockaddr_in client_addr = {};
		socklen_t socklen = sizeof(client_addr);
		
		int connfd = accept(fd, (struct sockaddr *)&client_addr, &socklen);
		if(connfd<0)
			continue;
		
		
		while(1)
		{
			
			int err= one_request(connfd);
			
			if(err)
			break;
			
			
		}
		close(connfd);
	}
	
}



static int32_t one_request(int connfd)
{
	
	char rbuf[4 + k_max_msg + 1];
	errno =0;
	int32_t err = read_full(connfd, rbuf, 4);
	
	if(err)
	{
		if(errno == 0)
		{
			printf("EOF\n");
		}
		else
		{
			printf("Read error\n");
		}
		return err;
	}
	
	uint32_t len =0;
	
	memcpy(&len,rbuf,4);
	
	if(len>k_max_msg)
	{
		printf("To long");
		return -1;
	}
	// request body

	err = read_full(connfd, &rbuf[4], len);
	if (err)
	{
		msg("read() error");
		return err;
	}
	rbuf[4 + len] = '\0';
	
	const char reply[] = "world";
	
	char wbuf[4 + sizeof(reply)];
	
	len = (uint32_t)strlen(reply);
	
	memcpy(wbuf, &len, 4);
	memcpy(&wbuf[4], reply, len);
	
	return write_all(connfd, wbuf, 4 + len);

}


static int read_full(int fd,char *buf,size_t size n)
{
	while(n>0)
	{
		ssize_t rv =read(fd,buf,n);
		if(rv<=0)
		{
			return -1;
		}
		
		assert((size_t)rv<=n);
		n-=(size_t)rv;
		
		buf+=rv;
		
	}
	
	return 0;
			
}

static int32_t write_all(int fd, const char *buf, size_t n)
{
	while(n>0)
	{
		ssize_t rv =write(fd,buf,n);
		if(rv<=0)
		{
			return -1;
		}
		
		assert((size_t)rv<=n);
		n-=(size_t)rv;
		
		buf+=rv;
		
	}
	
	return 0;
}

