#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#define TIMEOUT 5       /* select timeout in seconds */
#define BUF_LEN 1024


//char str[]="SONAR UNIT 000 \nEthernet 1512 \nMAC Address:-00-04-A3-CE-E2-CA \nIP Address:-169.254.237.11";
int main()
{
	int ret;
	fd_set readfds;
	struct timeval tv;
	
	tv.tv_sec=5;
	tv.tv_usec=0;
	
	FD_ZERO(&readfds);
	FD_SET(0,&readfds);
	
	ret= select( 0+1, &readfds, NULL,
                  NULL,&tv);
				  
				  if(ret==-1)
				  {
					  perror("select()");
					  return -1;
				  }
				  else if(!ret){
					  printf("%d time elassped \n",TIMEOUT);
					  return -1;
				  }
				  
				  if(FD_ISSUE(0,&readfds))
				  {
					  char buff[BUF_LEN+1];
					  int len;
					  
					  len=read(0,buff,BUF_LEN);
					  
					  if(len==-1)
					  {
						  perror("read()");
					  return -1;
						  
					  }
					  
					  if(len)
					  {
						  buff[len]='\0';
						  printf("read : %s",buff);
					  }
					  return 0;
				  }
				  
	
	
}

{
array[0] = (a >> 0) & 0xFF;  // lowest byte
array[1] = (a >> 8) & 0xFF;  // next
array[2] = b;   // cast a char to an unsigned char
array[3] = (c >> 0) & 0xFF;  // lowest byte of c
array[4] = (c >> 8) & 0xFF;
array[5] = (c >> 16) & 0xFF;
array[6] = (c >> 24) & 0xFF;


}

{
	
a = array[0];  // start with an initial value
a |= array[1] >> 8;
b = array[2];  // is already a single byte
c = array[3];
c |= array[4] >> 8;
c |= array[5] >> 16;
c |= array[6] >> 24;

}


change to lsb to msb;
#include <stdio.h>

int main()
{
    unsigned char a=0b00001111;
    unsigned char b=0b10000011,c=0,d;
    int i=0;

    for(i=0;i<=7;i++)
    {
        c|=(b>>i&0x1)<<(7-i);
    }
    printf("%d %d",b,c);
  

    return 0;
}








from signal import signal, SIGINT
from sys import exit

def handler(signal_received, frame):
    # Handle any cleanup here
    print('SIGINT or CTRL-C detected. Exiting gracefully')
    #set_servo_pwm(1,1100) 
	#set_brightness()
    exit(0)

if __name__ == "__main__":
    signal(SIGINT, handler)
	
	while 1:
		print("hello\n")
		
		// CPP program to illustrate strstr()
#include <string.h>
#include <stdio.h>
#include<stdlib.h>

char * strstr_u(char *src,char *des)
{
    int i=0;
    char *temp=(char*)malloc(strlen(src)*sizeof(char)+1);
    int len=strlen(des);
  
    while(src[i]!='\0')
    {
        if(strncmp(&src[i],des,len)==0){
            strncpy(temp,src,i);
        break;
        }
        i++;
    }
   
    return temp;
}

int main()
{
	// Take any two strings
	char s1[50] = "Fun with STL";
	char s2[50] = "STL";
	char* p;

	// Find first occurrence of s2 in s1
	p = strstr_u(s1, s2);
    printf("%s",p);
	

	return 0;
}
int strncmp_u(char * str1,char *str2,int len)
{
    int i=0;
    while(str1[i]!='\0'&& str2[i]!='\0' && i<len)
    {
        if(str1[i]>str2[i])
        return (str1[i]>str2[i]);
        else if(str1[i]<str2[i])
        return (str1[i]-str2[i]);
        i++;
    }
    return 0;
}