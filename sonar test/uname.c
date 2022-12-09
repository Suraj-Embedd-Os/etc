#include<stdio.h>
#include<unistd.h>
#include<sys/utsname.h>


int main()
{
	struct	utsname name;
	
	if(uname(&name)<0)
	{
		perror("uname()\n");
		return 0;
	}
	
	printf("sysname: %s\n",name.sysname);
	printf("nodename: %s\n",name.nodename);
	printf("release: %s\n",name.release);
	printf("version: %s\n",name.version);
	printf("machine: %s\n",name.machine);
	
	#ifdef	GNUSOURCE
	printf("domainname: %s\n",name.domainname);
	#endif 
	
	return  0;	
}

