

#include<iostream>
#include<cstdlib>
#include <sys/types.h>
#include <unistd.h>


using namespace std;

extern char **environ;


int main()
{
	int numb;
	char *p;
	putenv("DEMO=abcdefghijklmnop");
		
	p=getenv("DEMO");
	
	cout<<"Parent environ is 1 "<<p<<endl;
	if(fork()==0)
	{
		cout<<"child enter "<<endl;
		*(p+9)='X';
		
		p=getenv("DEMO");
	
		cout<<"child environ is 1 "<<p<<endl;
		return 0;
	}
		sleep(10);
		cout<<"back to parent "<<endl;
		p=getenv("DEMO");
		cout<<"Parent environ is 2 "<<p<<endl;
		
	
	
	return 0;
	
}

