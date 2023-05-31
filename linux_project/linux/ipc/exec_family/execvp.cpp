#include<iostream>
#include<stdio.h>
#include<unistd.h>

using namespace std;

int main(int argc,char*argv[])
{
	if(argc>1)
	{
	  execvp(argv[1], &argv[1]);
	  perror(" execvp ");
	  return -1;
	}
	cerr<<"Usage Error "<<*argv<<" file"<<endl;
	return 0;
}

