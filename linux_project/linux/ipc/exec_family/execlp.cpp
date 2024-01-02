#include<iostream>
#include<stdio.h>
#include<unistd.h>

using namespace std;

int main(int argc,char *argv[])
{

	if(argc>1)
	{

	 execlp("/bin/cat","cat",argv[1],(char*)NULL);
	 perror("exec failed\n");
	 return -1;
	}
	cerr<<"usage error"<<*argv<<"txt file"<<endl;

	return 0;
}
