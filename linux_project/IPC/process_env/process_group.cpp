
 
#include<iostream>
#include <sys/types.h>
#include <unistd.h>


using namespace std;

int main()
{
	
	cout<<"Initial process \tPID: "<<getpid()<<"\tPPID :"<<getppid()<<"\tPGID :"<<getpgid(getpid())<<endl;
	
	for(int i=0;i<3;i++)
	{
		if(fork()==0)
		{
			cout<<"\tPID: "<<getpid()<<"\tPPID :"<<getppid()<<"\tPGID :"<<getpgid(0)<<endl;
		}
	}
	return 0;
}
