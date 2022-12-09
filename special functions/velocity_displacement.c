#include <stdio.h>
#include<unistd.h>
#include <sys/time.h>
#include<stdbool.h>
#include<stdint.h>
float calcLength(int count);
void change_Displacment(int *count);
void recordTime(float *running_time);

/*

    velocity change in displacment with respect to time
*/

int main()
{
    int max_count=20;
    float app_running_tim=0.0f;
    int count=0,_temp_cnt=0;
    
    float disp1=0.0,disp2=1;
    float velocity=0.0;
	 float t1=0,t2=1;
	 
	 float length=0;
	 system("clear");
    while(1)
    {
        usleep(10000);
        printf("\033[s");
        recordTime(&app_running_tim);
        if(_temp_cnt% 60==0)
        {
            change_Displacment(&count);
            length=calcLength(count);
            _temp_cnt=0;
        }
        disp1=count;
		t1=app_running_tim;
        if(disp1!=disp2)
        {
			if((int)app_running_tim%1==0)
            velocity=(float)(disp2-disp1)/(t2-t1);
            //printf("\033[3;3H %f  %f %f\n",disp1,disp2,velocity);
            disp2=disp1;
			t2=t1;

        }
    //	printf("\033[1;3Happ_running_tim: %f count: %d fft\\sec\n velocity: %f\n",app_running_tim,count,velocity);
    //	printf("\033[4;3HDistance:  %f\n",length);
    	
    	_temp_cnt++;
    }
    

}




float calcLength(int count)
{

	float PPI;
	int PPR = 10;
	static float Length;
	float Radius = 1.84;
	float maxLength=0;
	int maxCount=499;
	float temp=0;
	
	
	/**********************************************************/
	static int prev_count;
	
	
	

	PPI = PPR/(2*3.14*Radius);	
	
	maxLength=(float)(maxCount/PPI)/12;
	
	//printf("maxLength %f ",maxLength);
	
	float f1;
	
	if(prev_count!=0 && prev_count!=1)
	{
	
	f1=(((float)count-prev_count)/PPI/12);
	

	 
	 Length=Length+f1;
	
	temp=Length;
	
	if(Length<0)
	{
		temp =maxLength+Length;
		temp*=-1;
	}
	
	printf("Length %f temp %f f1 %f prev_count %d count %d \n",Length,temp,f1,prev_count,count);

	prev_count=count;
	return temp;
	}
	Length=0;
		prev_count=count;
	return 0;
}



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
	
//	printf("sec %f usec %f running_time %f\n",sec,usec,*running_time);
	
}

void change_Displacment(int *count)
{
    static bool flag1=true,flag2=true;
    static int t_cnt=0;
    
  /*  if(t_cnt<20)
    (*count)++;
    else
    {
       (*count)--;  
       if((*count)==0)
       t_cnt=0;
    }
   
   t_cnt++;*/
   
   if(flag1)
   {
       (*count)++;
       if((*count)>=20)
       flag1=false;
   }
  else if(flag2)
  {
      (*count)--;
      if((*count)==0) {
      *count=20;
      flag2=false;
      }
  }
  else 
  {
      (*count)--;
      
      if((*count)==0){
      flag1=true;
      flag2=true;
      }
  }
    
    
}

