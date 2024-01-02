
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "command.h"

char sonar_ip[100];
char eth_ip[100];

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
	if(argc<2)
	{
		printf("Usage error pass ethernet ip address\n");
		return -1;
	}
	
	strcpy(eth_ip,argv[1]);
	//Brodcast discovery message to get mac and ip address informations
	profiler_discovery(eth_ip,rd_buff);
	
	//filter ip adress from read buffer
	get_ip_addr(rd_buff,sonar_ip);
	while(1)
	{
		//show_options();
		//select_options();
		get_sensor_data();
		perform_sweep();
		
	}
	return 0;
}



