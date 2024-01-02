
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>



int main()
{
	char cwd[100];
	struct sysinfo si;
	
	getcwd(cwd,100);
	
	sysinfo(&si);
	
	#if(0)
	 struct sysinfo {
               long uptime;             /* Seconds since boot */
               unsigned long loads[3];  /* 1, 5, and 15 minute load averages */
               unsigned long totalram;  /* Total usable main memory size */
               unsigned long freeram;   /* Available memory size */
               unsigned long sharedram; /* Amount of shared memory */
               unsigned long bufferram; /* Memory used by buffers */
               unsigned long totalswap; /* Total swap space size */
               unsigned long freeswap;  /* Swap space still available */
               unsigned short procs;    /* Number of current processes */
               char _f[22];             /* Pads structure to 64 bytes */
           };
	#endif
		   
	printf("Your user Id is %d\n",getuid());
	printf("Your effective user Id is %d\n",geteuid());
	
	printf("Your current working directory is %s\n",cwd);
	printf("Your machine has %ld MB of " "total RAM\n", si.totalram / 1024 / 1024); 
	printf("Your machine has %ld MB of " "free RAM\n", si.freeram / 1024 / 1024); 
	printf("Your machine has %ld MB of " "Swap Memory\n", si.totalswap / 1024 / 1024); 
	printf("Your machine has %ld MB of " "Total Freee Swap Memory\n", si.freeswap / 1024 / 1024); 
	printf("Currently, there are %d processes " "running\n", si.procs);
	printf("This process ID is %d\n", getpid()); 
	printf("The parent process ID is %d\n", getppid());
	return 0;

	
}
