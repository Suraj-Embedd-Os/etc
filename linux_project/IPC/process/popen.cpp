

#include<iostream>
#include<string.h>
#include <stdio.h>
#include<unistd.h>

using namespace std;

int main()
{
	char  buff[50];
	memset(buff,0,50);
	
	FILE *fp =popen("ps | grep  -v grep | grep -i asas|awk  '{print $1} '","r");
	
	if(fp==NULL)
	{
		perror("popen");
		exit(-1);
	}
	
	fgets(buff,50,fp);
	
	cout<<buff<<endl;
	
	fclose(fp); 
	
	return 0;
}

