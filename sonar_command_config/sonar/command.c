#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<math.h>
#include <sys/time.h>
#include<stdbool.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<errno.h>
#include"command.h"
#include"common_enum.h"

extern struct sonar_config_para *sonar_config;

/***
To read and write data to 1512E sonar.We need to broadcast command to all ip address and get back ip
and mac address informations.The recived IP adress used for send the command and recived data
from sonar.
***/ 
				
extern char sonar_ip[30];
extern char eth_ip[30];
extern char path_to_save[50];
extern int gsocketSD;
extern int encoderfd;
extern char timeBuff[100];
extern int hight;
extern int width;
extern int points;

/*
	read data from rotary encoder

*/

float recieve_from_encoder()
{
	float length=0.0f;
	char buff[80]={'\0'};
	
	if(write(encoderfd,"pulse data",10)<0)
	{
		perror("Request write()\n");
	}
	printf("Request pulse data \n");

	int n=read(encoderfd, buff, sizeof(buff));
	if(n<0)
	{
		perror("Pulse Read()");
	}
	length =atof(buff);
	printf("recived lenght data %s  %f\n",buff,length);

	return length;
	
	
}

void get_time_stamp1(char buff[],int _size)
{
	FILE *fp;
	

  /* Open the command for reading. */
  fp = popen("date +%H:%M:%S:%3N", "r"); // read time hours,min,sec,milisec
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  while (fgets(buff,_size-1,fp) != NULL) {
    printf("%s", buff);
  }
  
	buff[strcspn(buff, "\r\n")] = 0;
	printf("file name buff %s\n",buff);

  /* close */
  pclose(fp);

}
/*
	Application running record time  

*/
void recordTime(float *running_time)
{
	struct timeval  tv1;
	static uint8_t once=0;
	
	static double usec=0.0f,sec=0.0f;
	gettimeofday(&tv1, NULL);
	if(once==1)
	{
		if(running_time!=NULL)
			*running_time+=(double) (tv1.tv_usec - usec) / 1000000 +(double) (tv1.tv_sec - sec);
	}
	
	usec=tv1.tv_usec;
	sec=tv1.tv_sec;
	once=1;

	//printf("sec %f usec %f running_time %f\n",sec,usec,*running_time);
	
}
/*
	Create file with .pcd format
*/

void create_pcd_format(char *buff,int len)
{
	float _range=sonar_config->range;
	float _step_size=GetStepSizeDegrees(sonar_config->stepsize);
	static float _angle=0;
	//_temp=_step_size;
	int _no_of_step=GetNumberOfPings(sonar_config->arcsize,sonar_config->centerangle, \
	sonar_config->stepsize);

	float x_cordinat=0.0f;
	float y_cordinat=0.0f;
	float z_cordinat=0.0f;//recieve_from_encoder();
	float rgb=0.0f;
	printf("saving  data in .pcd format\n");
	
	// open file for write data in PCD format
	FILE *pcd_file=fopen(path_to_save,"a");
	printf("_step_size %f and _no_of_step %d\n",_step_size,_no_of_step);
	int i=0;
	static int step_cnt=0;

	static float running_time=0.0f;
	//recordTime(&running_time); // record time 

	while(_step_size<_no_of_step && buff[i]!='\r')
	{
		_angle=_step_size*step_cnt;

		//converted x,y -cordinate using polar cartesion
		x_cordinat=_range*cos(_angle);
		y_cordinat=_range*sin(_angle);


		 if(buff[i]!='+' || buff[i]!='-')
		 { 
			printf(" step_size %f x %f,y %f,z %f ,sweep_data %hhu\n",_angle,x_cordinat,y_cordinat,z_cordinat,buff[i]);
			fprintf(pcd_file,"%f %f %f %hhu\n",x_cordinat,y_cordinat,z_cordinat,buff[i]);
		}
		i++;
		
		
		step_cnt++;
		if(_angle>360)
		{
		 step_cnt=0;
		_angle=0;
		}
		points++;
	}

	printf("saved  data in .pcd format\n");
	fclose(pcd_file);

	// open file again for write down number of points
	pcd_file=fopen(path_to_save,"r+");
	int line = 0;
	char buffer[100];
    while ((fgets(buffer, 100, pcd_file)) != NULL)
    {
        line++;
        if (line == 7)
            fprintf(pcd_file,"POINTS %d\n",points);
       
    }
	fclose(pcd_file); 
}

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
	
	/*switch(choice)
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
	}*/
}

/*
brif@ read cable count
send command ='@'

*/

void get_cable_count(void)
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	char cmd[]={'@','0'};
	profile_survey(cmd,2,rd_data,10);
	printf(" RECIVE :: %s \n",rd_data);
	printf("...........................\n");
}
/*
brif@ read sensor data and save in file
send command ='D'
*/
void get_sensor_data(void)
{
	printf("...........................\n");
	//read data buffer
	char rd_data[250]={'\0'};
	//send command
	char cmd[]={'D'};
	int ret=-1;
	double  pitch , roll;
	//pass command and buffer to read data from sonar
	profile_survey(cmd,1,rd_data,250);
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
	printf("...........................\n");
}

/*
brif@: read version informations of the under water sonar unit
send command ='\r'
*/
void get_version(void)
{
	printf("...........................\n");
	//read data buffer
	char rd_data[50]={'\0'};
	
	char cmd[]={'\r'};
	profile_survey(cmd,1,rd_data,50);
	printf(" RECIVE :: %s \n",rd_data);
	printf("...........................\n");
}
/*
brif@: Locate to Zero sets the motor position on the underwater unit to 0 
	 (ready to start a clockwise sweep)
	 send command ='U'

*/
void locate_to_zero_position(void)
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	char cmd[]={'U'};
	profile_survey(cmd,1,rd_data,10);
	//printf(" RECIVE :: %s \n",rd_data);
	if(!strncmp((char *)&rd_data,(char *)&cmd,1))
		printf("motor position set to zero sucessfull\n");
	else
		printf("failed motor position set to zero \n");
		printf("...........................\n");
	
}

/*
brif@: Performs a full sweep and returns the data
send command ='W'
*/
void perform_sweep(void)
{
	printf("...........................\n");
	char rd_data[10000]={'\0'};
	char cmd[]={'W'};
	int ret=-1;
	
	
	char save_file[100];
	
	strcpy(save_file,path_to_save);
	strcat(save_file,timeBuff);
	
	printf("save_file file %s \n",save_file);
	
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
	char time_stamp[30];
	static unsigned int sweep_cnt=0;
	//TODO provide path to ssd
	//FILE *fp=fopen(save_file,"a");
	FILE *fp=fopen("./sweep_data.txt","a");
	//FILE *fp=fopen("/home/toad/AcepipeWorkspace/Sonar/sweep_data.txt","w");
	if(fp==NULL)
	{
		perror("failed to open\n");
		return;
	}
	else
	{
		sweep_cnt++;
		memset(time_stamp,0,30);
		get_time_stamp1(time_stamp,30);
		
		fprintf(fp,"sweep no %hu start time %s\n",sweep_cnt,time_stamp);
		memset(time_stamp,0,30);
		
		profile_survey(cmd,1,rd_data,10000);
		get_time_stamp1(time_stamp,30);
		fprintf(fp,"sweep no %hu end time %s\n\n",sweep_cnt,time_stamp);
		
		int i_temp=0;
			while(rd_data[i_temp]!='\r'){
				if(rd_data[i_temp]=='+' || rd_data[i_temp]=='-')
				{
					//fprintf(fp,"%c\n",rd_data[i_temp]);
					fputc((char)rd_data[i_temp],fp);
					printf("...%c\n",rd_data[i_temp]);
				}
				else
				fprintf(fp,"%hhu\n",rd_data[i_temp]);
				i_temp++;
			
			}
			
			printf("%d sweep data write sucessfull\n",i_temp);
			fclose(fp);
			//chdir("..");
	}

	create_pcd_format(rd_data,100);
	
	printf("...........................\n");
}

/*
brif@: Configures the cable counter. Settings are not saved therefore must be reapplied
	 each time the board is powered up.
send command ='Z' along with 32 bytes number
*/
void set_cable_counter_ticks()
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	
	char cmd[10]={'\0'};
	
	memset(cmd,0,sizeof(cmd));
	int ticks=0;
	
	printf("Set cable counter ticks :\n");
	scanf("%d",&ticks);
	cmd[0]='Z';
	cmd[1]=64;
	cmd[2]=((ticks>>24)&0xFF);
	cmd[3]=((ticks>>16)&0xFF);
	cmd[4]=((ticks>>8)&0xFF);
	cmd[5]=(ticks&0xFF);
	

	profile_survey(cmd,6,rd_data,10);
	//printf(" RECIVE :: %s \n",rd_data);
	if(!strncmp((char *)&rd_data,(char *)&cmd,1))
		printf("Configures the cable counter sucessfull\n");
	else
		printf("failed to configures the cable counter \n");
	
	printf("...........................\n");
}

/*
brif@: Sets the centre angle for each sweep.
	The motor cannot go past the start or the end position \
   therefore the centre angle should be chosen in accordance \
   with the scan arc size. 
   If the scan arc size is 360° then the only valid choice for the centre angle is 180°.
  Also for a centre angle of 30°, the scan arc can only be 60° or 30°.

*/
void set_centre_angle()
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	
		char cmd[5]={'\0'};
		strncpy(cmd,&sonar_config->centerangle,1);
		profile_survey(cmd,1,rd_data,10);
				//printf(" RECIVE :: %s \n",rd_data);
		if(!strncmp((char *)&rd_data,cmd,1))
		{
			printf("set center angle sucessfull\n");
		}
		else{
		printf("failed to set center angle \n");
		}
		
	printf("...........................\n");
}
/*
brif@: Sets the range resolution of the data capture.
*/
void set_number_of_samples()
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	unsigned char cmd[5]={'\0'};

	printf("sonar_config->sample %hu\n",sonar_config->sample);
	cmd[0]='Y';
	cmd[1]=(sonar_config->sample>>8)&0xFF;
	cmd[2]=(sonar_config->sample&0xFF);
    


	profile_survey(cmd,3,rd_data,10);
	//printf(" RECIVE :: %s \n",rd_data);
	if(!strncmp((char *)&rd_data,(char *)&cmd,1)){
		printf("set the range resolution sucessfull \n");
	}
	else{
		printf("failed to set the range resolution \n");
	}
	printf("...........................\n");		
}
/*
brif@: The oversamples setting controls the level of down sampling on the received data. 
		This setting is used to configure the range coverage and resolution of each sweep. 
		Valid oversamples choices are from 0  7. 
*/
void set_oversamples()
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	char cmd[5]={'\0'};
	cmd[0]='X';
	cmd[1]=sonar_config->oversample;
	printf("sonar_config->oversample %hhu\n",sonar_config->oversample);
	
		profile_survey(cmd,2,rd_data,10);
		//printf(" RECIVE :: %s \n",rd_data);
		
		if(!strncmp((char *)&rd_data,(char *)&cmd,1)){
		printf("set oversamples sucessfull\n");
		}
		else
		{
			printf("failed to set oversamples \n");
		}
		printf("...........................\n");
	
		
}
/*
brif@: The repeat rate is the time between each motor step when performing a sweep. 
This should be set to be at least the acoustic travel/
 time for the current range setting plus a small buffer to make sure. 
*/
void set_repeat_rate()
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	
	char cmd[5]={'\0'};
	strncpy(cmd,&sonar_config->repeatrate,1);

	profile_survey(cmd,1,rd_data,10);
				//printf(" RECIVE :: %s \n",rd_data);
				
				if(!strncmp((char *)&rd_data,(char *)&sonar_config->repeatrate,1)){
				printf("set repeat rate sucessfull\n");
				}
				else{
				printf("failed to set repeat rate \n");
			}
			printf("...........................\n");
}

/*
brif@: Sets the internal sampling rate for the data capture. 
The sample rate is in nanoseconds, with a minimum value of 200ns (5 MHz) per sample.
 The sample rate can only be incremented in multiples of 20ns. 
*/
void set_sample_rate()
{
	printf("...........................\n");
	char rd_data[5]={'\0'};
	char cmd[10]={'\0'};
	cmd[0]='V';
	cmd[1]=(sonar_config->samplerate>>8)&0xff;
	cmd[2]=(sonar_config->samplerate)&0xff;
	

	profile_survey(cmd,3,rd_data,5);
	
	if(!strncmp((char *)&cmd[0],(char *)&rd_data,1)){
		printf("set sample range  sucessfull\n");
			}
			else{
				printf("failed to set sample range\n");
				return;
			}
	printf("...........................\n");
}

/*
brif@:Sets the angular coverage for each sweep. . 
*/
void set_scan_arc_size()
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	

	char cmd[5]={'\0'};
	strncpy(cmd,&sonar_config->arcsize,1);

	profile_survey(cmd,1,rd_data,10);
				//printf(" RECIVE :: %s \n",rd_data);
				if(!strncmp((char *)&sonar_config->arcsize,(char *)&rd_data,1)){
					printf("set scan arc size sucessfull\n");
				}
				else
					printf("failed to set scan arc size\n");
	printf("...........................\n");
}

/*
brif@:Sets the step size used when the underwater unit performs a sweep. 
A single motor step is 0.9°. 
Larger angle settings step the motor multiple times between \
each transmit/receive cycle in order for the underwater unit to perform \
faster at the cost of angular resolution. 
*/
void set_step_size()
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	

			char cmd[5]={'\0'};
			strncpy(cmd,&sonar_config->stepsize,1);
			profile_survey(cmd,1,rd_data,10);
			printf(" RECIVE :: %s \n",rd_data);
			if(!strncmp(cmd,(char *)&rd_data,1))
			{
					printf("set step size sucessfull\n");
			}
			else
				printf("failed to set step size\n");
	printf("...........................\n");
}

/*
brif@:Sets transmit power of the sonar

*/
void set_tx_power()
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	
		char cmd[5]={'\0'};
		cmd[0]=']';
		cmd[1]=(char)sonar_config->txpower;
		//strncpy(&cmd[1],&sonar_config->txpower,1);
		profile_survey(cmd,2,rd_data,10);
		//printf(" RECIVE :: %s \n",rd_data);
		
		if(!strncmp((char *)&rd_data,(char *)&cmd,1)){
		printf("set tx_power sucessfull\n");
	
		}
		else
		{
			printf("failed to set tx_power \n");
		
		}
	printf("...........................\n");
}
/*
brif@:Sets transmit power pulse of the sonar

*/
void set_tx_pulse_width()
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	
	char cmd[5]={'\0'};
	strncpy(cmd,&sonar_config->pulsewidth,1);

	profile_survey(cmd,1,rd_data,10);
				//printf(" RECIVE :: %s \n",rd_data);
				if(!strncmp(cmd,(char *)&rd_data,1)){
					printf("set tx_pulse_width sucessfull\n");
		
				}
				else
					printf("failed to tx_pulse_width\n");
	printf("...........................\n");
}
/*
brif@: Moves the underwater unit's motor 1 step anti-clockwise.
 There are 400 motor positions covering the 360° sonar scan arc. 
 If the motor is already fully anti-clockwise then the motor is not moved
 and a data error message is returned instead of the standard response.

*/
void step_motor_anti_clockwise(void)
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	char cmd[]={'C'};
	profile_survey(cmd,1,rd_data,10);
	printf(" RECIVE :: %s \n",rd_data);
	printf("...........................\n");
}
/*
brif@: Moves the underwater unit's motor 1 step clockwise.
 There are 400 motor positions covering the 360° sonar scan arc. 
 If the motor is already fully anti-clockwise then the motor is not moved
 and a data error message is returned instead of the standard response.

*/
void step_motor_clockwise(void)
{
	printf("...........................\n");
	char rd_data[10]={'\0'};
	char cmd[]={'B'};
	profile_survey(cmd,1,rd_data,10);
	//printf(" RECIVE :: %s \n",rd_data);
	printf("...........................\n");
}

/*
brif@: send discovery command and read back MAC and IP address information 
		from sonar unit.
		command send='D';

*/

void profiler_discovery(char *eth_ip_addr,char *rd_buff,int _size)
{
	
	//Create socket descriptor for UDP communication
    int socketSD = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socketSD <= 0) {
       perror("socket failed()");
        exit(0);
    }
    
    // set socket options enable broadcast
    int broadcastEnable = 1;
	struct timeval tv;
	tv.tv_sec = 2;
	tv.tv_usec = 0;
    int ret = setsockopt(socketSD, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    if (ret) {
         perror("setsockopt failed()");
        close(socketSD);
         exit(0);
    }
	 ret = setsockopt(socketSD, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));
    if (ret) {
         perror("setsockopt failed()");
        close(socketSD);
         exit(0);
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
    sockaddr.sin_addr.s_addr = inet_addr(eth_ip_addr);//inet_addr("169.254.237.110");//htonl(INADDR_ANY);//inet_addr("169.254.237.110");//;
    
	// Bind the socket
    int status = bind(socketSD, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    if (status == -1) {
        close(socketSD);
          perror(" bind()");
         exit(0);
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
    ssize_t result = recvfrom(socketSD, rd_buff, _size, 0, (struct sockaddr *)&receiveSockaddr, &receiveSockaddrLen);
   
   //display ip and port form recived
	printf("Recive from:: %s port::%d\n",inet_ntoa(receiveSockaddr.sin_addr),htons(receiveSockaddr.sin_port));
	printf("RECIVE :: %s \n\r",rd_buff);
	printf("...........................\n");
	
    close(socketSD);
    
    
}
/*
brif@: send  command and read response  from sonar unit.

*/
void profile_survey(unsigned char * cmd,int _cmd_len,char *rd_buff,int _size)
{
	
	// Configure the port and ip we want to send to
    struct sockaddr_in broadcastAddr;
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));
    broadcastAddr.sin_family = AF_INET;
	
	printf("ethernet ip::%s sonar ip::%s\n",eth_ip,sonar_ip);
    broadcastAddr.sin_addr.s_addr=inet_addr(sonar_ip);//inet_addr("192.168.60.211");
    broadcastAddr.sin_port = htons(12345);

    unsigned char *request = cmd;
	// Send command message
    int ret = sendto(gsocketSD, (char *)request,_cmd_len, 0, (struct sockaddr*)&broadcastAddr, sizeof(broadcastAddr));
    if (ret < 0) {
        perror("sendto failed()");
        close(gsocketSD);
        return;
    }
	/*printf("send command to server ip %s  and port::%d\n",inet_ntoa(broadcastAddr.sin_addr),htons(broadcastAddr.sin_port));
    printf("command sent\n");
	printf("...........................\n");*/
	
	
	//recive data structure
    struct sockaddr_in receiveSockaddr;
	memset(&receiveSockaddr,0,sizeof(receiveSockaddr));
    socklen_t receiveSockaddrLen = sizeof(receiveSockaddr);
    
    //size_t bufSize = 9216;
   // char buf[bufSize];
	//memset(buf,'\0',sizeof(buf));
	
	// receive ip ,device and mac informations
    ssize_t result = recvfrom(gsocketSD, (unsigned char*)&rd_buff[0],  _size, 0, (struct sockaddr *)&receiveSockaddr, &receiveSockaddrLen);
   
   //display ip and port form recived
	//printf("Recive from:: %s port::%d\n",inet_ntoa(receiveSockaddr.sin_addr),htons(receiveSockaddr.sin_port));
	//printf(" data %s \n",rd_buff);

	// To read array of bytes of sweep data 
	if(strncmp(cmd,"W",1)==0){
			//printf(" RECIVE :: %s \n",rd_buff);
			memset(rd_buff,'\0',_size);
			recvfrom(gsocketSD, rd_buff, _size, 0, (struct sockaddr *)&receiveSockaddr, &receiveSockaddrLen);
			
		}
	// close(socketSD); 
}

int create_socket()
{
	
	//Create socket descriptor for UDP communication
    int socketSD = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socketSD <= 0) {
       perror("socket failed()");
         exit(0);
    }
    
    // set socket options enable broadcast
    int broadcastEnable = 1;
	struct timeval tv;
	tv.tv_sec = 2;
	tv.tv_usec = 0;
    int ret = setsockopt(socketSD, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    if (ret) {
         perror("setsockopt failed()");
        close(socketSD);
        exit(0);
    }
	  //ret = setsockopt(socketSD, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));
    /*if (ret) {
         perror("setsockopt failed()");
        close(socketSD);
         exit(0);
		}*/
    
    

    
	
	// bind the port
    struct sockaddr_in sockaddr;
    memset(&sockaddr, 0, sizeof(sockaddr));
   
    //sockaddr.sin_len = sizeof(sockaddr);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(12345);
    sockaddr.sin_addr.s_addr = inet_addr(eth_ip); //inet_addr("192.168.60.99");   
	// Bind the socket
    int status = bind(socketSD, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    if (status == -1) {
        close(socketSD);
          perror(" bind()");
        exit(0);
    }
	
	return socketSD;
	
}