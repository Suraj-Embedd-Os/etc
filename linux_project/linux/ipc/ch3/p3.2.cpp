#include<stdio.h>
#include<string.h>
#include<iostream>
#include<unistd.h>
#include<sys/types.h>

using namespace std;

int main()
{
	static char buffer[10];

	if(fork()==0)
	{
		strcpy(buffer,"CHILD..");
	}
	else
	{
		strcpy(buffer,"PARRENT..");
	}

	for(int i=0;i<10;i++)
	{
		sleep(1);
		write(1,buffer,sizeof(buffer));
	}
	return 0;
}


