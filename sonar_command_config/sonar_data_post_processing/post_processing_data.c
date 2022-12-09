
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

enum { X_AXIS,Y_AXIS,Z_AXIS,DATA,TIMESTAMP,TL_SONAR_PARAM };
enum { DISTANCE ,TIME,TL_ENCODER_PARAM };

void filter_sonar_data(char *data,float *act_data);
void filter_encoder_data(char *data,float *act_data);


int main()
{
 FILE *fp_sonar =fopen("sweep_data.pcd","r");
 FILE *fp_encoder =fopen("Encoder_data.txt","r");
  FILE *fp_post =fopen("post_sweep_data.pcd","w");
 
 char sonar_rd_buff[100];
 char encoder_rd_buff[100];
 
 float sonar_data[TL_SONAR_PARAM];
 float encoder_data[TL_ENCODER_PARAM];

	long long int point_write=0;
   if(fp_sonar==NULL || fp_encoder==NULL || fp_post==NULL)
   {
	   perror("unable to open");
       exit(-1);
   }
   
   int cnt=0;
   while(cnt!=9)
   {
    fgets(sonar_rd_buff,100,fp_sonar);
	fputs(sonar_rd_buff,fp_post);
    cnt++;
   }
   
   fclose(fp_post);
   
   fp_post =fopen("post_sweep_data.pcd","a");
   
    if(fp_post==NULL)
   {
	   perror("unable to open");
       exit(-1);
   }
   int _tmp_cnt=0;
  while(fgets(sonar_rd_buff,100,fp_sonar)!=NULL) 
   {
	   
	   fgets(encoder_rd_buff,100,fp_encoder);
       filter_sonar_data(sonar_rd_buff,sonar_data);
	   filter_encoder_data(encoder_rd_buff,encoder_data);
	   
	   printf("x %f y %f z %f intensity %f s_time %f distance %f e_time %f \n",sonar_data[X_AXIS], \
	   sonar_data[Y_AXIS],sonar_data[Z_AXIS],sonar_data[DATA],sonar_data[TIMESTAMP], \
	   encoder_data[DISTANCE], encoder_data[TIME]);
	   
	   while(encoder_data[TIME]>=sonar_data[TIMESTAMP])
	   {
		   fprintf(fp_post,"%f %f %f %f\n",sonar_data[X_AXIS],sonar_data[Y_AXIS],encoder_data[DISTANCE],sonar_data[DATA]);
		   point_write++;
		   if(fgets(sonar_rd_buff,100,fp_sonar)==NULL)
			   break;
		   filter_sonar_data(sonar_rd_buff,sonar_data);
		   _tmp_cnt++;
	   }
	   fprintf(fp_post,"%f %f %f %f\n",sonar_data[X_AXIS],sonar_data[Y_AXIS],encoder_data[DISTANCE],sonar_data[DATA]);
	    point_write++;
	   _tmp_cnt++;
	   
   }
   
   printf("\n\n %d %lld\n",_tmp_cnt,point_write);
   fclose(fp_post); 
   
   
   fp_post =fopen("post_sweep_data.pcd","r+");
   if(fp_post==NULL)
   {
	   perror("unable to open");
       exit(-1);  
   }
	
	int line = 0;
	char buffer[100];
    while ((fgets(buffer, 100, fp_post)) != NULL)
    {
        line++;
        if (line == 7)
            fprintf(fp_post,"POINTS %lld\n",point_write);
       
    }
   
   fclose(fp_sonar);
   fclose(fp_encoder);
   fclose(fp_post);

    return 0;
}

/*
@brif :

*/

void filter_sonar_data(char *data,float *act_data)
{
    char file_data[5][15];
    int i=0,k=0,cnt=0;
    while(data[i]!='\n')
    {
        if(data[i]!=' ')
        {
            file_data[cnt][k++]=data[i];
        }
        else
        {
            file_data[cnt][k]='\0';
            cnt++;
            k=0;
        }
        i++;
    }
	
    if(act_data!=NULL)
	{
		for(i=0;i<5;i++)
		act_data[i] =atof(file_data[i]);
	}
      
}

/*
@brif :

*/

void filter_encoder_data(char *data,float *act_data)
{
    float time,distance;
    char data_arr[2][10];
    
    char *p1=strstr(data,"Distance: ");
    p1+=strlen("Distance: "); //skip Distance: 
    
    
    char *p2=strstr(data,"Time: ");
    p2+=strlen("Time: "); //skip Time: 
    
    strncpy(data_arr[0],p1,10);
    strncpy(data_arr[1],p2,10);
    
    
   //printf("%s %s \n",data_arr[0],data_arr[1]);
   
   if(act_data!=NULL)
   {
    act_data[0]=atof(data_arr[0]);
    act_data[1]=atof(data_arr[1]);
    
   }
    //printf("%f %f \n",act_data[0],act_data[1]);
    
    
}