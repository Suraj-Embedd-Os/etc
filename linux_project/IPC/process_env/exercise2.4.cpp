

#include<iostream>
#include <sys/types.h>
#include <unistd.h>


using namespace std;

int main()
{
	
		int child;
		char buff[10];
		
		FILE *fp=fopen("./temp.txt","r");
		
		if(fp==NULL)
		{
			perror("fopen");
			return -1;
		}
		
		child=fork();
		
		if(child==0)
		{
			cout<<"child process running \n";
			fgets(buff,10,fp);
			cout<<"childs read from file :"<<buff<<endl;
			return 0;
			
		}
		sleep(5);
		cout<<"parent process running \n";
		fgets(buff,10,fp);
		cout<<"parent read from file :"<<buff<<endl;;
		return 0;
}
