


#include<iostream>
#include<cstdlib>
#include <sys/types.h>
#include <unistd.h>
 #include <fcntl.h>

using namespace std;

int main()
{
		pid_t get_pid,proc_pid;
		char buff[20];
		
		get_pid=getpid();
		
		readlink("/proc/self",buff,20);
		proc_pid=atoi(buff);
		
		cout<<"get_pid "<<get_pid<<" proc_pid "<<proc_pid<<endl;
	return 0;
}
