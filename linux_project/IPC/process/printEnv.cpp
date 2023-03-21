

#include<iostream>

using namespace std;

extern char **environ;
int main()
{
	
	while(*environ)
	{
		cout<<*environ++<<endl;
	}
	return 0;
	
}