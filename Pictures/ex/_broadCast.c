

#include <stdio.h>          
#include <string.h>         
#include <stdlib.h>
  #include <sys/types.h>    
  #include <netinet/in.h>   
  #include <sys/socket.h>   
  #include <arpa/inet.h>    
  #include <fcntl.h>        
  #include <netdb.h>        
  #include <unistd.h>



#define  PORT_NUM           30303  // Port number used


void main(int argc,char *argv[])
{

  int                  client_s;        // Client socket descriptor
  struct sockaddr_in   server_addr;     // Server Internet address
  int                  addr_len;        // Internet address length
  char                 out_buf[4096];   // Output buffer for data
  char                 in_buf[4096];    // Input buffer for data
  int                  retcode;         // Return code
  int                  iOptVal;         // Socket option value
  int                  iOptLen;         // Socket option length



  // Create a socket
  client_s = socket(AF_INET, SOCK_DGRAM, 0);
  if (client_s < 0)
  {
    printf("*** ERROR - socket() failed \n");
    exit(-1);
  }

  // Fill-in server socket's address information
  server_addr.sin_family = AF_INET;                 // Address family to use
  server_addr.sin_port = htons(PORT_NUM);           // Port num to use
  server_addr.sin_addr.s_addr = inet_addr("169.254.28.71"); // Need this for Broadcast

  // Set socket to use MAC-level broadcast
  iOptVal = 1;
  iOptLen = sizeof(int);
  if((setsockopt(client_s, SOL_SOCKET, SO_BROADCAST, (char*)&iOptVal, iOptLen))<0)
  {
	  printf("failed to set socket behaviour\n");
	  exit(-1);
  }

  // Assign a message to buffer out_buf
  strncpy(out_buf, argv[1],strlen(argv[1])+1);

  // Now send the message to server.
  retcode = sendto(client_s, out_buf, (strlen(out_buf) + 1), 0,
    (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (retcode < 0)
  {
    printf("*** ERROR - sendto() failed \n");
    exit(-1);
  }
	printf("send sucessfull\n");
	printf("Wait for receive a message....  \n");
  // Wait to receive a message
  addr_len = sizeof(server_addr);
  retcode = recvfrom(client_s, in_buf, sizeof(in_buf), 0,
    (struct sockaddr *)&server_addr, &addr_len);
  if (retcode < 0)
  {
    perror("recvfrom():");
    exit(-1);
  }

  // Output the received message
  printf("Received from server: %s \n", in_buf);

  // Close all open sockets


  retcode = close(client_s);
  if (retcode < 0)
  {
    printf("*** ERROR - close() failed \n");
    exit(-1);
  }


}