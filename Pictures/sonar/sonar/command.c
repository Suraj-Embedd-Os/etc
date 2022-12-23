#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<math.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<errno.h>
#include "command.h"

/***
To read and write data to 1512E sonar.We need to broadcast command to all ip address and get back ip
and mac address informations.The recived IP adress used for send the command and recived data
from sonar.
***/ 
				
extern char sonar_ip[30];
extern char eth_ip[30];
extern char path_to_save[30];

/*
	brif@: 	helper to clear input stream
*/
void clear_input_stream()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }	
	//while ( getchar() != '\n' );
}

/*
brif@: 	helper function to get coordinate
para@:	int short data
return  short int
*/

static double get_cordinate(int short temp)
{
 
 if ((temp & 2048) > 0) 
	 temp = (int short)(-2048 + (temp & 2047));
 else temp = (int short)(temp & 2047); 
	//double x = (double)temp;
	return (double)temp;
}
/*
brif@: 	helper function to extact sensor data from the string 
para@:	string ,index and no of byte to extact
return  short int
*/
static short int get_num16(char  str[],int index,int num_byte)
{
    char temp[10]={'\0'};
    int i,j=0;
    for(i=index;i <(index+num_byte);i++)
		{
			temp[j++]=str[i];   
		}  
    temp[j]='\0';
   
    short int num =(short int)strtol(temp,0,16);
   
	return num;
}
/*
brif@: 	helper function to get pitch and roll data
para@:	pass pointer to pitch and roll; of the directory
*/
static void get_pitch_roll(double * pitch ,double *roll, char *rd_data)
{
	double x=0.0f,y=0.0f,z=0.0f;
	
	x=get_cordinate(get_num16(rd_data,4,3));
	y=get_cordinate(get_num16(rd_data,10,3));
	z=get_cordinate(get_num16(rd_data,26,3));
	
	*pitch =atan(-x / sqrt(pow(y, 2.0) + pow(z, 2.0)));
	*roll  =atan2(y, z);
	return;
}
/*
brif@: 	helper function to know dir is already exits
para@:	pass path of the directory
*/
static int is_dir_exists(const char* const path)
{
  struct stat info;

        int statRC = stat( path, &info );
            if( statRC != 0 )
			{
				if (errno == ENOENT)  
				{ 
					return 0; 
				} // something along the path does not exist
                  if (errno == ENOTDIR)
					  {
						return 0; 
					  } // something in path prefix is not a dir
                       return -1;
             }
		return ( info.st_mode & S_IFDIR ) ? 1 : 0;
}
/*
brif@ show the option for sonar

*/
void show_options(void)
{
	
	printf("\n\t1.GET_CABLE_COUNT\n");
	printf("\t2.GET_SENSOR_DATA\n");
	printf("\t3.GET_VERSION\n");
	printf("\t4.LOCATE_TO_ZERO_POSITIONS\n");
	printf("\t5.PERFORM_SWEEP\n");
	printf("\t6.SET_CABLE_COUNTER_TICKS\n");
	printf("\t7.SET_CENTER_ANGLE\n");
	printf("\t8.SET_NUMBER_OF_SAMPLE\n");
	printf("\t9.SET_OVERSAMPLES\n");
	printf("\t10.SET_REPEAT_RATE\n");
	printf("\t11.SET_SAMPLE_RATE\n");
	printf("\t12.SET_SCAN_ARC_SIZE\n");
	printf("\t13.SET_STEP_SIZE\n");
	printf("\t14.SET_TX_POWER\n");
	printf("\t15.SET_TX_PULSE_WIDTH\n");
	printf("\t16.STEP_MOTOR_ANTI_CLOCKWISE\n");
	printf("\t17.STEP_MOTOR_CLOCKWISE\n");
	//printf("\tEnter other to exit\n");
	printf("\tEnter your options :\t");
	
}

/*
brif@  option for configure and read data from sonar

*/
void select_options(void)
{
	int choice=-1;
	scanf("%d",&choice);
	printf("\n");
	system("clear");
	
	switch(choice)
	{
		case GET_CABLE_COUNT:
			get_cable_count();
		break;
		case GET_SENSOR_DATA:
			get_sensor_data();
		break;
		case GET_VERSION:
			get_version();
		break;
		case LOCATE_TO_ZERO_POSITIONS:
			locate_to_zero_position();
		break;
		case PERFORM_SWEEP:
			perform_sweep();
		break;
		case SET_CABLE_COUNTER_TICKS:
			set_cable_counter_ticks();
		break;
		case SET_CENTER_ANGLE:
			set_centre_angle();
		break;
		
		case SET_NUMBER_OF_SAMPLE:
			set_number_of_samples();
		break;
		case SET_OVERSAMPLES:
			set_oversamples();
		break;
		case SET_REPEAT_RATE:
			set_repeat_rate();
		break;
		case SET_SAMPLE_RATE:
			set_sample_rate();
		break;
		case SET_SCAN_ARC_SIZE:
			set_scan_arc_size();
		break;
		case SET_STEP_SIZE:
			set_step_size();
		break;
		case SET_TX_POWER:
			set_tx_power();
		break;
		case SET_TX_PULSE_WIDTH:
			set_tx_pulse_width();
		break;
		case STEP_MOTOR_ANTI_CLOCKWISE:
			step_motor_anti_clockwise();
		break;
		case STEP_MOTOR_CLOCKWISE:
			step_motor_clockwise();
		break;
		
		default:
		clear_input_stream();
		break;
	}
}

/*
brif@ read cable count
send command ='@'

*/

void get_cable_count(void)
{
	char rd_data[10]={'\0'};
	char cmd[]={'@','0'};
	profile_survey(cmd,rd_data);
	printf(" RECIVE :: %s \n",rd_data);
}
/*
brif@ read sensor data and save in file
send command ='D'
*/
void get_sensor_data(void)
{
	//read data buffer
	char rd_data[250]={'\0'};
	//send command
	char cmd[]={'D'};
	int ret=-1;
	double  pitch , roll;
	//pass command and buffer to read data from sonar
	profile_survey(cmd,rd_data);
	printf(" RECIVE :: %s \n",rd_data);
	/*if(!is_dir_exists("1512E"))
	{
		ret =mkdir("./1512E",0777);
		if(ret<0)
		{
			perror("failed to create directory\n");
			return;
		}
	}
	 ret=chdir("1512E");
	if(ret<0)
	{
		perror("failed to change directory\n");
		return;
	}*/
	
	if(!strncmp((char *)&rd_data,(char *)&cmd,1))
	{
		//open file for write sensor data
		//TODO provide path to ssd
		//FILE *fp=fopen("path_to_save/sensor_data.txt","w");
		FILE *fp=fopen("sensor_data.txt","w"); //TODO 
		if(fp==NULL)
		{
			perror("failed to open");
			return;
		}
		else
		{
			
			get_pitch_roll(&pitch,&roll,(char*)&rd_data);
			
			//write data in file
			fprintf(fp,"Motor Position :%hi\n",get_num16(rd_data,2,3));
			fprintf(fp,"Pitch :%lf\n",pitch);
			fprintf(fp,"Roll  :%lf\n",roll);
			fprintf(fp,"Temperature :%hi\n",get_num16(rd_data,14,3));
			fprintf(fp,"Bearing :%hi\n",get_num16(rd_data,18,3));
			fprintf(fp,"Depth :%hi\n",get_num16(rd_data,22,3));
			fprintf(fp,"Z Axis :%hi\n",get_num16(rd_data,26,3));
			fprintf(fp,"Spare :%hi\n",get_num16(rd_data,30,3));
			fprintf(fp,"Supply Voltage :%hi\n",get_num16(rd_data,34,3));
			fprintf(fp,"Reserved :%hi",get_num16(rd_data,38,9));
			
			//close file
			fclose(fp);
			//chdir("..");
		
		}
	}
	
}

/*
brif@: read version informations of the under water sonar unit
send command ='\r'
*/
void get_version(void)
{
	//read data buffer
	char rd_data[50]={'\0'};
	
	char cmd[]={'\r'};
	profile_survey(cmd,rd_data);
	printf(" RECIVE :: %s \n",rd_data);
}
/*
brif@: Locate to Zero sets the motor position on the underwater unit to 0 
	 (ready to start a clockwise sweep)
	 send command ='U'

*/
void locate_to_zero_position(void)
{
	char rd_data[10]={'\0'};
	char cmd[]={'U'};
	profile_survey(cmd,rd_data);
	//printf(" RECIVE :: %s \n",rd_data);
	if(!strncmp((char *)&rd_data,(char *)&cmd,1))
		printf("motor position set to zero sucessfull\n");
	else
		printf("failed motor position set to zero \n");
	
}

/*
brif@: Performs a full sweep and returns the data
send command ='W'
*/
void perform_sweep(void)
{
	char rd_data[10000]={'\0'};
	char cmd[]={'W'};
	int ret=-1;
	profile_survey(cmd,rd_data);
	/*if(!is_dir_exists("1512E"))
	{
		ret =mkdir("./1512E",0777);
		if(ret<0)
		{
			perror("failed to create directory\n");
			return;
		}
	}
	 ret=chdir("1512E");
	if(ret<0)
	{
		perror("failed to change directory\n");
		return;
	}*/
	
	//TODO provide path to ssd
	FILE *fp=fopen("path_to_save/sweep_data.txt","w");
	if(fp==NULL)
	{
		perror("failed to open");
		return;
	}
	else
	{
		int i_temp=0;
			while(rd_data[i_temp]!='\r')
			fprintf(fp,"%hhu\n",rd_data[i_temp++]);
			//printf("write sweep data sucessfull\n");
			fclose(fp);
			//chdir("..");
	}
	
	
}

/*
brif@: Configures the cable counter. Settings are not saved therefore must be reapplied
	 each time the board is powered up.
send command ='Z' along with 32 bytes number
*/
void set_cable_counter_ticks()
{
	char rd_data[10]={'\0'};
	
	char cmd[10];
	
	memset(cmd,0,sizeof(cmd));
	int ticks=0;
	
	printf("Set cable counter ticks :\n");
	scanf("%d",&ticks);
	cmd[0]='Z';
	cmd[1]=64;
	/*cmd[2]=((ticks>>24)&0xFF);
	cmd[3]=((ticks>>16)&0xFF);
	cmd[4]=((ticks>>8)&0xFF);
	cmd[5]=(ticks&0xFF);*/
	
	char temp=((ticks>>24)&0xFF);
	int i=0;
	for(i=0;i<=7;i++)
    {
        cmd[2]|=(temp>>i&0x1)<<(7-i);
    }
	
	 temp=((ticks>>16)&0xFF);
	for(i=0;i<=7;i++)
    {
        cmd[3]|=(temp>>i&0x1)<<(7-i);
    }
	
	 temp=((ticks>>8)&0xFF);
	for(i=0;i<=7;i++)
    {
        cmd[4]|=(temp>>i&0x1)<<(7-i);
    }
	
	 temp=(ticks&0xFF);
	for(i=0;i<=7;i++)
    {
        cmd[5]|=(temp>>i&0x1)<<(7-i);
    }
	
	profile_survey(cmd,rd_data);
	//printf(" RECIVE :: %s \n",rd_data);
	if(!strncmp((char *)&rd_data,(char *)&cmd,1))
		printf("Configures the cable counter sucessfull\n");
	else
		printf("failed to configures the cable counter \n");
	
}

/*
brif@: Sets the centre angle for each sweep.
	The motor cannot go past the start or the end position \
   therefore the centre angle should be chosen in accordance \
   with the scan arc size. 
   If the scan arc size is 360° then the only valid choice for the centre angle is 180°.
  Also for a centre angle of 30°, the scan arc can only be 60° or 30°.

*/
void set_centre_angle(void)
{
	char rd_data[10]={'\0'};
	char center_angle[11]={'"','#','$','%','&','\"','(',')','*',',','.'};
	//char cmd;
	int8_t choice =-1;
	printf("\n");
	system("clear");
	do{
		choice=-1;
		printf("\t0.set center angle 30 degree\n");
		printf("\t1.set center angle 60 degree\n");
		printf("\t2.set center angle 90 degree\n");
		printf("\t3.set center angle 120 degree\n");
		printf("\t4.set center angle 150 degree\n");
		printf("\t5.set center angle 180 degree\n");
		printf("\t6.set center angle 210 degree\n");
		printf("\t7.set center angle 240 degree\n");
		printf("\t8.set center angle 270 degree\n");
		printf("\t9.set center angle 300 degree\n");
		printf("\t10.set center angle 330 degree\n");
		printf("\tEnter any key to return\n");
		printf("\tselecte center angle :\t");
		
		scanf("%hhi",&choice);
		printf("\n");
		system("clear");
			if(choice >=0 && choice <=10){
				profile_survey((unsigned char*)&center_angle[choice],rd_data);
				//printf(" RECIVE :: %s \n",rd_data);
					if(!strncmp((char *)&rd_data,(char *)&center_angle[choice],1))
					{
					printf("set center angle sucessfull\n");
					sleep(2);
					break;
					}
					else
					printf("failed to set center angle \n");
					
					}
			else {
				clear_input_stream();
				return;
			}
	}while(choice>=0 && choice<=10);
	
	
}
/*
brif@: Sets the range resolution of the data capture.
*/
void set_number_of_samples(void)
{
	char rd_data[10]={'\0'};
	char cmd[5]={'\0'};
	int unsigned short no_sample=0;
	char temp=0;
	
	do{
	no_sample=0;
	printf("\nEnter no of sample range(400 600) :\n");
	scanf("%hu",&no_sample);
	printf("\n");
	system("clear");
	cmd[0]='Y';
	/*if(no_sample>255)
	{
		cmd[0]='Y';
		cmd[1]=(no_sample>>8)&0xFF;
		cmd[2]=(no_sample&0xFF);
	}
	/else if(no_sample>0 && no_sample<255)
	{
		cmd[0]='Y';
		cmd[1]=(no_sample&0x00FF);
	}*/

	 temp=((no_sample>>8)&0xFF);
	 int i;
	for(i=0;i<=7;i++)
    {
        cmd[1]|=(temp>>i&0x1)<<(7-i);
    }
	
	 temp=(no_sample&0xFF);
	for(i=0;i<=7;i++)
    {
        cmd[2]|=(temp>>i&0x1)<<(7-i);
    }
	profile_survey(cmd,rd_data);
	//printf(" RECIVE :: %s \n",rd_data);
	if(!strncmp((char *)&rd_data,(char *)&cmd,1)){
		printf("set the range resolution sucessfull \n");
		sleep(2);
		break;
	}
	else{
		clear_input_stream();
		printf("failed to set the range resolution \n");
	}
	
	}while(1);
			
}
/*
brif@: The oversamples setting controls the level of down sampling on the received data. 
		This setting is used to configure the range coverage and resolution of each sweep. 
		Valid oversamples choices are from 0 – 7. 
*/
void set_oversamples()
{
	
	char rd_data[10]={'\0'};
	char cmd[5]={'\0'};
	int os_val=-1;
	
	
	do
	{
		os_val=-1;
		printf("Enter over sample range(0-7): ");
		scanf("%d",&os_val);
		printf("\n");
		system("clear");
		if(os_val>=0 && os_val<=7)
		{
		cmd[0]='X';
		cmd[1]=(char)os_val;
		profile_survey(cmd,rd_data);
		//printf(" RECIVE :: %s \n",rd_data);
		
		if(!strncmp((char *)&rd_data,(char *)&cmd,1)){
		printf("set oversamples sucessfull\n");
		sleep(2);
		break;
		}
		else
		{
			clear_input_stream();
			printf("failed to set oversamples \n");
		
		}
		}
		else
		{
			clear_input_stream();
			return;
		}
	}while(os_val>=0 && os_val<=7);
	
	return;	
		
}
/*
brif@: The repeat rate is the time between each motor step when performing a sweep. 
This should be set to be at least the acoustic travel/
 time for the current range setting plus a small buffer to make sure. 
*/
void set_repeat_rate(void)
{
	char rd_data[10]={'\0'};
	char repeat_rate[10]={'K','L','M','N','O','P','Q','R','S','T'};	
	int8_t choice=-1;
	printf("\n");
	system("clear");
	do{
		choice=-1;
		printf("\t0.set repeat rate 200us\n");
		printf("\t1.set repeat rate 500us\n");
		printf("\t2.set repeat rate 1ms\n");
		printf("\t3.set repeat rate 1.5ms\n");
		printf("\t4.set repeat rate 2ms\n");
		printf("\t5.set repeat rate 3ms\n");
		printf("\t6.set repeat rate 4ms\n");
		printf("\t7.set repeat rate 5ms\n");
		printf("\t8.set repeat rate 7ms\n");
		printf("\t9.set repeat rate 10ms\n");
		printf("\tEnter any key to return\n");
		printf("\tselect repeat rate :\t");
		scanf("%hhi",&choice);
		printf("\n");
		system("clear");
			if(choice >=0 && choice <=9){
				profile_survey((unsigned char*)&repeat_rate[choice],rd_data);
				//printf(" RECIVE :: %s \n",rd_data);
				
				if(!strncmp((char *)&rd_data,(char *)&repeat_rate[choice],1)){
				printf("set repeat rate sucessfull\n");
				sleep(2);
				break;
				}
				else
				printf("failed to set repeat rate \n");
			}
			else
			{
				clear_input_stream();
				return;
			}
	}while(choice >=0 && choice <=9);
}

/*
brif@: Sets the internal sampling rate for the data capture. 
The sample rate is in nanoseconds, with a minimum value of 200ns (5 MHz) per sample.
 The sample rate can only be incremented in multiples of 20ns. 
*/
void set_sample_rate(void)
{
	char rd_data[5]={'\0'};
	char cmd[10]={'\0'};
	cmd[0]='V';
	unsigned short  sample_rate=-1;
	printf("\n");
	system("clear");
	char temp=0;
	do
	{
	sample_rate=-1;
	printf("Enter sample range multiple of 20ns minimum (200ns): ");
	scanf("%hu",&sample_rate);

	/*cmd[1]=(sample_rate>>8)&0xff;
	cmd[2]=(sample_rate)&0xff;*/
	
	 temp=((sample_rate>>8)&0xFF);
	 int i;
	for(i=0;i<=7;i++)
    {
        cmd[1]|=(temp>>i&0x1)<<(7-i);
    }
	
	temp=(sample_rate&0xFF);
	for(i=0;i<=7;i++)
    {
        cmd[2]|=(temp>>i&0x1)<<(7-i);
    }
	profile_survey(cmd,rd_data);
	
	if(!strncmp((char *)&cmd[0],(char *)&rd_data,1)){
		printf("set sample range  sucessfull\n");
		sleep(2);
		break;	
			}
			else
			{
				printf("failed to set sample range\n");
				//clear input stream
				clear_input_stream();
				return;
			}
	
	}while(1);
	
	return;
}

/*
brif@:Sets the angular coverage for each sweep. . 
*/
void set_scan_arc_size(void)
{
	char rd_data[10]={'\0'};
	char arc_size[10]={'0','1','2','3','4','5','6','7','8','9'};	
	int8_t choice=-1;
		printf("\n");
		system("clear");
	do{
		choice=-1;
		printf("\t0.set scan arc size 30 degree\n");
		printf("\t1.set scan arc size 60 degree\n");
		printf("\t2.set scan arc size 90 degree\n");
		printf("\t3.set scan arc size 120 degree\n");
		printf("\t4.set scan arc size 150 degree\n");
		printf("\t5.set scan arc size 180 degree\n");
		printf("\t6.set scan arc size 210 degree\n");
		printf("\t7.set scan arc size 240 degree\n");
		printf("\t8.set scan arc size 270 degree\n");
		printf("\t9.set scan arc size 360 degree\n");
		printf("\tEnter any key to return\n");
		printf("\tselect scan arc size :\t");
		
		scanf("%hhi",&choice);
		printf("\n");
		system("clear");
			if(choice >=0 && choice <=9){
				profile_survey((unsigned char*)&arc_size[choice],rd_data);
				//printf(" RECIVE :: %s \n",rd_data);
				if(!strncmp((char *)&arc_size[choice],(char *)&rd_data,1)){
					printf("set scan arc size sucessfull\n");
					sleep(2);
					break;
				}
				else
					printf("failed to set scan arc size\n");
			}
			else
			{
				//clear input stream
				clear_input_stream();
				return;
			}
	}while(choice >=0 && choice <=9);
}

/*
brif@:Sets the step size used when the underwater unit performs a sweep. 
A single motor step is 0.9°. 
Larger angle settings step the motor multiple times between \
each transmit/receive cycle in order for the underwater unit to perform \
faster at the cost of angular resolution. 
*/
void set_step_size(void)
{
	char rd_data[10]={'\0'};
	char step_size[4]={':',';','<','>'};	
	int8_t choice=-1;
		printf("\n");
		system("clear");
	do{
		choice=-1;
		printf("\t0.set step size 0.9 degree\n");
		printf("\t1.set step size 1.8 degree\n");
		printf("\t2.set step size 2.7 degree\n");
		printf("\t3.set step size 3.6 degree\n");
		printf("\tEnter any key to return\n");
		printf("\tselect step size :\t");
		scanf("%hhi",&choice);
		printf("\n");
		system("clear");
			if(choice >=0 && choice <=3){
				profile_survey((unsigned char*)&step_size[choice],rd_data);
				//printf(" RECIVE :: %s \n",rd_data);
				if(!strncmp((char *)&step_size[choice],(char *)&rd_data,1)){
					printf("set step size sucessfull\n");
					sleep(2);
					break;
				}
				else
					printf("failed to set step size\n");
			}
			else
			{
				clear_input_stream();
				return;
			}
	}while(choice >=0 && choice <=3);
}

/*
brif@:Sets transmit power of the sonar

*/
void set_tx_power(void)
{
	char rd_data[10]={'\0'};
	char cmd[5]={'\0'};
	int tx_power=-1;
	
	
	do
	{
		tx_power=-1;
		printf("Enter tx_power range(0-7): ");
		scanf("%d",&tx_power);
		printf("\n");
		system("clear");
		if(tx_power>=0 && tx_power<=7)
		{
		cmd[0]=']';
		cmd[1]=(char)tx_power;
		profile_survey(cmd,rd_data);
		//printf(" RECIVE :: %s \n",rd_data);
		
		if(!strncmp((char *)&rd_data,(char *)&cmd,1)){
		printf("set tx_power sucessfull\n");
		sleep(2);
		break;
		}
		else
		{
			clear_input_stream();
			printf("failed to set tx_power \n");
		
		}
		}
		else
		{
			clear_input_stream();
			return;
		}
	}while(tx_power>=0 && tx_power<=7);
	
	return;	
}
/*
brif@:Sets transmit power pulse of the sonar

*/
void set_tx_pulse_width(void)
{
	char rd_data[10]={'\0'};
	char tx_pulse_width[6]={'E','F','G','H','I','J'};	
	int8_t choice=-1;
		printf("\n");
		system("clear");
	do{
		choice=-1;
		printf("\t0.set tx_pulse_width to 2us\n");
		printf("\t1.set tx_pulse_width to 4us\n");
		printf("\t2.set tx_pulse_width to 8us \n");
		printf("\t3.set tx_pulse_width to 12us \n");
		printf("\t4.set x_pulse_width  to 16us \n");
		printf("\t5.set tx_pulse_width to 20us \n");
		
		printf("\tEnter any key to return\n");
		printf("\tselect tx_pulse_width :\t");
		scanf("%hhi",&choice);
		printf("\n");
		system("clear");
			if(choice >=0 && choice <=5){
				profile_survey((unsigned char*)&tx_pulse_width[choice],rd_data);
				//printf(" RECIVE :: %s \n",rd_data);
				if(!strncmp((char *)&tx_pulse_width[choice],(char *)&rd_data,1)){
					printf("set tx_pulse_width sucessfull\n");
					sleep(2);
					break;
				}
				else
					printf("failed to tx_pulse_width\n");
			}
			else
			{
				clear_input_stream();
				return;
			}
	}while(choice >=0 && choice <=5);
	return;
}
/*
brif@: Moves the underwater unit's motor 1 step anti-clockwise.
 There are 400 motor positions covering the 360° sonar scan arc. 
 If the motor is already fully anti-clockwise then the motor is not moved
 and a data error message is returned instead of the standard response.

*/
void step_motor_anti_clockwise(void)
{
	char rd_data[10]={'\0'};
	char cmd[]={'C'};
	profile_survey(cmd,rd_data);
	printf(" RECIVE :: %s \n",rd_data);
}
/*
brif@: Moves the underwater unit's motor 1 step clockwise.
 There are 400 motor positions covering the 360° sonar scan arc. 
 If the motor is already fully anti-clockwise then the motor is not moved
 and a data error message is returned instead of the standard response.

*/
void step_motor_clockwise(void)
{
	char rd_data[10]={'\0'};
	char cmd[]={'B'};
	profile_survey(cmd,rd_data);
	printf(" RECIVE :: %s \n",rd_data);
}

/*
brif@: send discovery command and read back MAC and IP address information 
		from sonar unit.
		command send='D';

*/

void profiler_discovery(char *eth_ip_addr,char *rd_buff)
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
	//inet_pton(AF_INET, "169.254.237.110", &broadcastAddr.sin_addr);
	broadcastAddr.sin_addr.s_addr=inet_addr("255.255.255.255");
    broadcastAddr.sin_port = htons(30303);
    
	
	// bind the port
    struct sockaddr_in sockaddr;
    memset(&sockaddr, 0, sizeof(sockaddr));
   
    //sockaddr.sin_len = sizeof(sockaddr);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(30303);
    sockaddr.sin_addr.s_addr = inet_addr(*eth_ip_addr);//htonl(INADDR_ANY);//inet_addr("169.254.237.110");//;
    
	// Bind the socket
    int status = bind(socketSD, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    if (status == -1) {
        close(socketSD);
          perror(" bind()");
        return;
    }
	
    char *request = "D";
	// Send Discovery message
    ret = sendto(socketSD, request, strlen(request), 0, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr));
    if (ret < 0) {
        perror("sendto failed()");
        close(socketSD);
        return;
    }
	printf("Broadcast to server ip %s  and port::%d\n",inet_ntoa(broadcastAddr.sin_addr),htons(broadcastAddr.sin_port));
    printf("Discovery message sent\n");
	printf("...........................\n");
	
	
	//recive data structure
    struct sockaddr_in receiveSockaddr;
	memset(&receiveSockaddr,0,sizeof(receiveSockaddr));
    socklen_t receiveSockaddrLen = sizeof(receiveSockaddr);
    
   /* size_t bufSize = 9216;
    char buf[bufSize];
	memset(buf,'\0',sizeof(buf));*/
	
	// receive ip ,device and mac informations
    ssize_t result = recvfrom(socketSD, rd_buff, sizeof(rd_buff), 0, (struct sockaddr *)&receiveSockaddr, &receiveSockaddrLen);
   
   //display ip and port form recived
	printf("Recive from:: %s port::%d\n",inet_ntoa(receiveSockaddr.sin_addr),htons(receiveSockaddr.sin_port));
	printf("RECIVE :: %s \n\r",rd_buff);
	printf("...........................\n");
	
    close(socketSD);
    
    
}
/*
brif@: send  command and read response  from sonar unit.

*/
void profile_survey(unsigned char * cmd,char *rd_buff)
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
	
    broadcastAddr.sin_addr.s_addr=inet_addr(sonar_ip);
    broadcastAddr.sin_port = htons(12345);
    
	
	// bind the port
    struct sockaddr_in sockaddr;
    memset(&sockaddr, 0, sizeof(sockaddr));
   
    //sockaddr.sin_len = sizeof(sockaddr);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(12345);
    sockaddr.sin_addr.s_addr = inet_addr(eth_ip);   
	// Bind the socket
    int status = bind(socketSD, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    if (status == -1) {
        close(socketSD);
          perror(" bind()");
        return;
    }
	
    unsigned char *request = cmd;
	// Send command message
    ret = sendto(socketSD, (char *)request, strlen(request), 0, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr));
    if (ret < 0) {
        perror("sendto failed()");
        close(socketSD);
        return;
    }
	printf("send command to server ip %s  and port::%d\n",inet_ntoa(broadcastAddr.sin_addr),htons(broadcastAddr.sin_port));
    printf("command sent\n");
	printf("...........................\n");
	
	
	//recive data structure
    struct sockaddr_in receiveSockaddr;
	memset(&receiveSockaddr,0,sizeof(receiveSockaddr));
    socklen_t receiveSockaddrLen = sizeof(receiveSockaddr);
    
    //size_t bufSize = 9216;
   // char buf[bufSize];
	//memset(buf,'\0',sizeof(buf));
	
	// receive ip ,device and mac informations
    ssize_t result = recvfrom(socketSD, rd_buff,  100, 0, (struct sockaddr *)&receiveSockaddr, &receiveSockaddrLen);
   
   //display ip and port form recived
	printf("Recive from:: %s port::%d\n",inet_ntoa(receiveSockaddr.sin_addr),htons(receiveSockaddr.sin_port));
	//printf(" RECIVE :: %s \n",rd_buff);
	//printf("...........................\n");

	// To read array of bytes of sweep data 
	if(strncmp(cmd,"W",1)==0)
		{
			//printf(" RECIVE :: %s \n",rd_buff);
			memset(rd_buff,'\0',sizeof(rd_buff));
			recvfrom(socketSD, rd_buff, 50000, 0, (struct sockaddr *)&receiveSockaddr, &receiveSockaddrLen);
			/*int i=0;
			while(rd_buff[i]!='\r')
				printf("%hhu\n",rd_buff[i++]);*/
		}
	 close(socketSD); 
	 return;
}

