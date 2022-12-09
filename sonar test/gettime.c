 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <time.h>
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

int main()
{
	char time[30];
	getTime(time);
	return 0;
}