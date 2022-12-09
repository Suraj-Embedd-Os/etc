
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
#include "command.h"
#include"common_enum.h"

char sonar_ip[30]="192.168.60.211"; //default ip adress to read data from sonar
char eth_ip[30]="192.168.60.209"; // default static ip of sonar to brodcast message
char path_to_save[30]="/home/toad/";
char timeBuff[100];
void getTime(char buff[]);

int gsocketSD=-1;

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
	if(argc!=2)
	{
		printf("Usage error pass <Sonar Ethernet IP Address> \n");
		return -1;
	}
	
	strcpy(eth_ip,argv[1]);
	//strcat(path_to_save,argv[2]);
	//Brodcast discovery message to get mac and ip address informations
	profiler_discovery(eth_ip,rd_buff,200);
	
	//filter ip adress from read buffer
	get_ip_addr(rd_buff,sonar_ip);
	printf("ip=%s\n\n",sonar_ip);

	//

    gsocketSD=create_socket();
	printf("gsocketSD %d \n",gsocketSD);
	sonar_initializations();
	

	getTime(timeBuff);
	
	/*while(1)
	{
		show_options();
		select_options();
		//get_sensor_data();
		//perform_sweep();
		
	}*/
	close(gsocketSD);
	return 0;
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


