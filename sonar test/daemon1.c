#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<syslog.h>
#include<fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <signal.h>
 #include <sys/time.h>
 #include <sys/resource.h>
 



void daemonize(const char *cmd)
{
	int i,fd0,fd1,fd2;
	pid_t pid;
	struct rlimit	r1;
	struct sigaction	sa;
	
	umask(0);
	
	
	if(getrlimit(RLIMIT_NOFILE,&r1)<0)
	{
		printf("%s can't get file limit",cmd);
		exit(0);
	}
	
	if((pid=fork())<0)
	{
		perror("fork()");
		exit(0);
	}
	else if(pid!=0)
		exit(0);
	
	setsid();
	
	sa.sa_handler=SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	
	if(sigaction(SIGHUP,&sa,NULL)<0)
	{
		printf("%s: can’t ignore SIGHUP", cmd);
		exit(0);
	}
	
	if((pid=fork())<0)
	{
		perror("fork()");
		exit(0);
	}
	else if(pid!=0)
		exit(0);
	
	if(chdir("/")<0)
	{	
		printf("%s: can’t change chdir ", cmd);
		exit(0);
	}
	
	if(r1.rlim_max==RLIM_INFINITY)
		r1.rlim_max=1024;
	for(i=0;i<r1.rlim_max;i++)
		close(i);

		fd0=open("/dev/null",O_RDWR);
		fd1=dup(0);
		fd2=dup(0);
		
	openlog(cmd,LOG_CONS,LOG_DAEMON);
	
	if(fd1!=0 || fd2!=0 || fd0!=0)
	{
			syslog(LOG_ERR, "unexpected file descriptors %d %d %d",
		fd0, fd1, fd2);
		exit(1);
	}
		
}

int main(int argc,char *argv[])
{
	daemonize(argv[0]);
	return 0;
}
		


