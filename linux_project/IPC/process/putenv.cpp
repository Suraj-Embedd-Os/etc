

#include<iostream>
#include<cstdlib>
#include <sys/types.h>
#include <unistd.h>


using namespace std;

extern char **environ;

int show_env(char **);
int main()
{
	int numb;
	cout<<"Parent before any addition"<<endl;
	show_env(environ);
	putenv("PARENT_ED=parent");
	cout<<"Parent aftre one addition"<<endl;
	show_env(environ);
	
	if(fork()==0)
	{
		
		cout<<"Child before any addition"<<endl;
		show_env(environ);
		putenv("CHILD_ED=Child");
		cout<<"Child aftre one addition"<<endl;
		show_env(environ);
		return 0;
	}
		sleep(10);
		cout<<"parent after done child addition"<<endl;
		
	numb=show_env(environ);
	 cout << "... and at address [" << hex << environ+numb<< "] is ... "<< (*(environ+numb) == NULL ? "Nothing!" : *(environ+numb))<< endl; 
	
	return 0;
	
}


int show_env(char ** cp)
{
	int i;
	for(i=0;*cp;++cp,++i)
		cout<<"["<<hex<<cp<<"]"<<*cp<<endl;
	return i;	
	
}