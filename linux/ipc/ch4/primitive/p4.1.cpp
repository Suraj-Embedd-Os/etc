#include<iostream>
#include<unistd.h>
#include"lock_file.h"

using namespace std;

int main(int argc,char *argv[])
{
	int numb_tries,i=5;
	int sleep_time;

	char *fname;

	set_defaults(argc,argv,&numb_tries,&sleep_time,&fname);

	if(acquire(numb_tries,sleep_time,fname))
	{
		while(--i)
		{
			cout<<getpid()<<" "<<i<<endl;
			sleep(sleep_time);
		}
		release(fname);
		return 0;
	}
	else
		cerr<<getpid()<<"Unable to obtain lock file after "<<numb_tries<<"tries."<<endl;
		return 1;
}



