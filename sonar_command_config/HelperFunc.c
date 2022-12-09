/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void get_time_stamp1(char buff[],int _size)
{
	FILE *fp;
	

  /* Open the command for reading. */
  fp = popen("date +%H:%M:%S:%3N", "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  while (fgets(buff,_size-1,fp) != NULL) {
    printf("%s", buff);
  }
  
	buff[strcspn(buff, "\r\n")] = 0;
	//printf("file name buff %s\n",buff);

  /* close */
  pclose(fp);

}

void getTimeinInt(char tim[],int arr[])
{
    int i=0;
    char str[4][4];
    int cnt=0;
    int k=0;
    while(tim[i]!='\0')
    {
        if(tim[i]!=':')
        {
           str[cnt][k++]=tim[i]; 
        }
        else
        {
         str[cnt][k]='\0';
         cnt++;
          k=0;
        }
         i++;
    }
    
    arr[0]=atoi(str[0]);
    arr[1]=atoi(str[1]);
    arr[2]=atoi(str[2]);
    arr[3]=atoi(str[3]);

    
    printf("%s %s %s %s \n",str[0],str[1],str[2],str[3]);
}

int main()
{
  
    char buff[100];
    get_time_stamp1(buff,100);
    
    int timeArr[4];
    
    getTimeinInt(buff,timeArr);
    
    printf("%d %d %d %d \n",timeArr[0],timeArr[1],timeArr[2],timeArr[3]);
 
    return 0;
}



#include <stdio.h>
#include<unistd.h>
#include <sys/time.h>

int main()
{

float app_running_tim=0.0f;
struct timeval  tv1, tv2;
 while(1)
  {
	gettimeofday(&tv1, NULL);
	usleep(5000);
	gettimeofday(&tv2, NULL);
	app_running_tim+=(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +(double) (tv2.tv_sec - tv1.tv_sec);

	printf("\033[s");

	printf("\033[10;10Happ_running_tim: %f\n",app_running_tim);
  }

    return 0;
}


#include <stdio.h>
#include<unistd.h>
#include <sys/time.h>
#include<stdbool.h>
#include<stdint.h>

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
	
	printf("sec %f usec %f running_time %f\n",sec,usec,*running_time);
	
}
