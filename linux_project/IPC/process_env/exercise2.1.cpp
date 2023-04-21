

#include<iostream>
#include <sys/types.h>
#include <unistd.h>


using namespace std;

int main()
{
	
		int child;
		
		child=fork();
		
		if(child==0)
		{
			sleep(5);
			cout<<"child called \n"<<getppid();
		}
		cout<<"Parent exit \n";
		return 0;
}
