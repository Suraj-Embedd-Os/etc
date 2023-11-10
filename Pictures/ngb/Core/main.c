/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<unistd.h>
#include<math.h>
#include"rms.h"
#define PI  (3.14123f)

int adc_return()
{
    static int degree =0;
    degree+=9;
    
    if(degree>359)
        degree=0;
    
    return degree;
}

float radin(int degree)
{
    return (((float)degree*PI)/180);
}
static int cnt=0;
 uint32_t  sample_arr[9];
void adc_call_back()
{
   int i;
    while(1)
    {
       usleep(125);
        int32_t temp=(int32_t)4096*sin(radin(adc_return()));
        if (temp<0)
        temp*=-1;
        //printf("%d \n",temp);
        for(i=0;i<9;i++)
        {
            sample_arr[i]=temp;
        }
        Adc_Sample_Calculations(sample_arr,0);
        cnt++;
         //printf(" cnt %d\n",cnt);
        if(cnt>TOTAL_NO_SAMPLE)
        {
           // printf(" cnt %d\n",cnt);
            cnt=0;
            Store_Adc_Data();
        }
    }
}

int main()
{
   float a=sin(radin(9));
   
   adc_call_back();

    return 0;
}
