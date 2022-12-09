
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <time.h>
#include "command.h"

char sonar_ip[30]="192.168.60.211"; //default ip adress to read data from sonar
char eth_ip[30]="192.168.60.99"; // default static ip of sonar to brodcast message
char path_to_save[100]="/media/toad/Data/AcePipe_Data";
char timeBuff[100];
void getTime(char buff[]);
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
	char rd_buff[200]; // stored mac and ip address informations
	/*if(argc!=3)
	{
		printf("Usage error pass <IP Address> only\n");
		return -1;
	}*/
	
	strcpy(eth_ip,argv[1]);
	strcpy(path_to_save,argv[2]);
	//strcat(path_to_save,"/sweep_data/");
	//Brodcast discovery message to get mac and ip address informations
	profiler_discovery(eth_ip,rd_buff,200);
	
	//filter ip adress from read buffer
	get_ip_addr(rd_buff,sonar_ip);
	//printf("path_to_save:%s \n",path_to_save);
	printf("sonar_ip %s eth_ip:%s \n",sonar_ip,eth_ip);
	
	while(1)
	{
		//show_options();
		//select_options();
		getTime(timeBuff);
		//get_sensor_data();
		perform_sweep();
		//usleep(500000);
		sleep(1);
		
	}
	return 0;
}


void getTime(char buff[])
{
	FILE *fp;
	char tim_buff[100];

  /* Open the command for reading. */
  fp = popen("date -u +%Y%m%d-%H%M%S", "r");
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




