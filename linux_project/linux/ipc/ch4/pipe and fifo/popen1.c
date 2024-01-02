#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 1000


int main(int argc, char **argv)
 {
	 int n;
	 char buff[MAXLINE] , command[MAXLINE];
	 FILE *fp;
	
	 fgets(buff, MAXLINE, stdin);
	 n = strlen(buff); 
	 if (buff[n - 1] == '\n')
	 n--;
	 snprintf(command, sizeof(command), "cat %s", buff);
	 fp = popen(command, "r");
	 
	 while (fgets(buff, MAXLINE, fp) != NULL)
	 fputs(buff, stdout);
	 pclose (fp);
	 exit(0);
}

