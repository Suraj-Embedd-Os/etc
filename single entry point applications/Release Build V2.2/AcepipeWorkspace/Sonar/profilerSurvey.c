
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
#include "command.h"
#include"common_enum.h"

#include <pthread.h>

#define PORT 8080
#define MAX 80

#define VERSION		(1.0f)

int create_socket_get_rotary_encoder_data();

char sonar_ip[30]="192.168.60.211"; //default ip adress to read data from sonar
char eth_ip[30]="192.168.60.209"; // default static ip of sonar to brodcast message
char path_to_save[50]="/media/toad/Data1/AcePipe_Data";
char timeBuff[100];
void getTime(char buff[]);

int hight=1;
int width=213;
long unsigned int points=0;

int gsocketSD=-1;
int encoderfd=-1;

//fiter ip address from string recive from soanr 
void get_ip_addr( char *src,char *des)
{
    char *ip=strstr(src,"IP Address");
     ip=strstr(ip,"-");
     ip+=strlen("-");
     strcpy(des,ip);
    
}

int main(int argc,char* argv[])
{
	char rd_buff[200];//="SONAR UNIT 000 Ethernet 1512 MAC Address:-00-04-A3-CE-E2-CA IP Address:-169.254.237.11";; // stored mac and ip address informations
	if(argc!=3)
	{
		printf("Usage error pass <Sonar Ethernet IP Address > <Paths  > \n");
		return -1;
	}
	
	#if(1)
	strcpy(eth_ip,argv[1]);
	strcpy(path_to_save,argv[2]);
	strcat(path_to_save,"sweep_data.pcd");
	//Brodcast discovery message to get mac and ip address informations
	profiler_discovery(eth_ip,rd_buff,200);
	
	//filter ip adress from read buffer
	get_ip_addr(rd_buff,sonar_ip);
	printf("ip=%s\n\n",sonar_ip);

	//

	//create socket for read data from sonar
    gsocketSD=create_socket();
	printf("gsocketSD %d \n",gsocketSD);
	
	//Intialised sonar configurations
	sonar_initializations();


	//create socket for encoder data read from host machine
	// encoderfd=create_socket_get_rotary_encoder_data();

	printf("open file for saving .pcd format\n");
	FILE *pcd_file=fopen(path_to_save,"w");
	printf("path_to_save %s",path_to_save);
	//FILE *pcd_file=fopen("sweep_data.pcd","w");
	if(pcd_file==NULL)
	{
		perror("fopen()\n");
		exit(-1);
	}
	fprintf(pcd_file,"VERSION %f\n",VERSION);
	fprintf(pcd_file,"FIELDS x y z rgb\n");
	fprintf(pcd_file,"SIZE 4 4 4 4\n");
	fprintf(pcd_file,"TYPE F F F F\n");
	fprintf(pcd_file,"COUNT 1 1 1 1 \n");
	fprintf(pcd_file,"WIDTH %d\n",width);
	fprintf(pcd_file,"HEIGHT %d\n",hight);
	fprintf(pcd_file,"POINTS %lu\n",points);
	fprintf(pcd_file,"DATA ascii \n");
	fclose(pcd_file);

	#endif
	
	//getTime(timeBuff);
	
	while(1)
	{
		//show_options();
		//select_options();
		//get_sensor_data();
		 perform_sweep();
		 usleep(5000);
		
	}
	close(gsocketSD);
	//close(encoderfd);
	return 0;
}




int create_socket_get_rotary_encoder_data()
{
	
	int sockfd;
	struct sockaddr_in servaddr;

	// socket create and verification
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
		bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("192.168.60.205");
	servaddr.sin_port = htons(PORT);

	// connect the client socket to server socket
	if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}
	else
		printf("connected to the server 192.168.60.205 \n");

		return sockfd;
}



void getTime(char buff[])
{
	FILE *fp;
	char tim_buff[100];

  /* Open the command for reading. */
  fp = popen("date +%Y%m%d-%H%M%S", "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  while (fgets(tim_buff, sizeof(tim_buff), fp) != NULL) {
    printf("%s", tim_buff);
  }
  
	tim_buff[strcspn(tim_buff, "\r\n")] = 0;
	strcat(tim_buff,".txt");
	strcpy(buff,tim_buff);
	printf("file name buff %s\n",buff);

  /* close */
  pclose(fp);

}
