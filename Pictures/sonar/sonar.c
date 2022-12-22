
short int get_num16(char  str[],int index,int num_byte)
{
    char temp[100];
    int i,j=0;
    for(i=index;i <(index+num_byte);i++)
		{
			temp[j++]=str[i];   
		}  
    temp[i]='\0';
   
    short int num =(short int)strtol(temp,0,16);
   // printf("%d",num);
	return num;
}
char str[]="Dm000p051r7FFt000g000h008i000j000v988k00000000";
double pitch = atan(-x / sqrt(pow(y, 2.0) + pow(z, 2.0))); 
result = pitch * 180.0/PI; //in degree
double  roll =atan2(y, z);
result = roll * 180.0/PI; //in degree

int short xTemp = get_num16(receivedBytes, 6, 3);
 if ((xTemp & 2048) > 0) 
	 xTemp = (int short)(-2048 + (xTemp & 2047));
 else xTemp = (int short)(xTemp & 2047); 
 double x = (double)xTemp;
 
void func(int centreAngle,int scanArc){
	
	short int stepsPerPing = 1; //1 for 0.9° steps, 2 for 1.8° and so on 
	float centre = round((centreAngle / 360) * 400);          
	float sector = round(((scanArc / 360) * 400) / 2); 
	short int sweepStart = (short int)(centre - sector); 
	short int sweepStop = (short int)(centre + sector - 1);
  
	if (sweepStart < 0) 
		sweepStart = 0;
	if (sweepStop > 399) 
		sweepStop = 399; 
	short int stepCount = 0; 
	while (sweepStart < sweepStop)
		{ 
		stepCount++;
		sweepStart += stepsPerPing;
	 } 
	 stepCount++;

	printf(" %h ",stepCount);
}

float range = (samples * (sampleRate * pow(10.0, -9.0)) *  pow(2.0, oversamples) * vos) / 2.0; 

void set_msb_first(char *str,short int num)
{
	str[1]=((num>>8)&0x7F));
	str[2]=(num&0x7F);
}


/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<string.h>
#include<math.h>



double get_cordinate(int short temp);
short int get_num16(char  str[],int index,int num_byte);

int main()
{
 
 char str[]="Dm000p051r7FFt000g000h008i000j000v988k00000000";
 
 short int x,y,z;
 
 //x=get_num16(str, 6,3);
 //y=get_num16(str, 10,3);
 //z=get_num16(str, 26,3);
 
 double x = cordinate(get_num16(str, 6, 3));
 double y = cordinate(get_num16(str, 10, 3));
 double z = cordinate(get_num16(str, 26, 3));
 
 double pitch = atan(-x / sqrt(pow(y, 2.0) + pow(z, 2.0))); 
 //result = pitch * 180.0/PI; //in degree
 double  roll =atan2(y, z);
 //result = roll * 180.0/PI; //in degree

    return 0;
}

double get_cordinate(int short temp)
{
 
 if ((temp & 2048) > 0) 
	 temp = (int short)(-2048 + (temp & 2047));
 else temp = (int short)(temp & 2047); 
	//double x = (double)temp;

	return (double)temp;
}	

short int get_num16(char  str[],int index,int num_byte)
{
    char temp[20];
    int i,j=0;
    for(i=index;i <(index+num_byte);i++)
		{
			temp[j++]=str[i];   
		}  
    temp[i]='\0';
 
   // printf("%s\n",temp);
    short int num =(short int)strtol(temp,NULL,16);
   // printf("%d\n",num);
	return num;
}

void get_ip_addr( char *src,char *des)
{
    char *ip=strstr(src,"IP Address");
     ip=strstr(ip,"-");
     ip+=strlen("-");
     strcpy(des,ip);
     printf("%s\n",des);  
}