#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler1(int signo)
{
  if (signo == SIGINT)
    printf("received SIGINT\n");
	sleep(5);
}
void sig_handler2(int signo)
{
  if (signo == SIGHUP)
    printf("received SIGHUP\n");
	sleep(5);
}
void sig_handler3(int signo)
{
  if (signo == SIGKILL)
    printf("received SIGKILL\n");
	sleep(5);
}
void sig_handler4(int signo)
{
  if (signo == SIGTRAP)
    printf("received SIGTRAP\n");
	sleep(5);
}

int main(void)
{
  if (signal(SIGINT, sig_handler1) == SIG_ERR)
  printf("\ncan't catch SIGINT\n");

  if (signal(SIGHUP, sig_handler2) == SIG_ERR)
  printf("\ncan't catch SIGHUP\n");

  if (signal(SIGKILL, sig_handler3) == SIG_ERR)
  printf("\ncan't catch SIGKILL\n");

  if (signal(SIGTRAP, sig_handler4) == SIG_ERR)
  printf("\ncan't catch SIGTRAP\n");
  // A long long wait so that we can easily issue a signal to this process
  while(1) 
    sleep(1);
  return 0;
}

