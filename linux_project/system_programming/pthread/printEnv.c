#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	extern char **environ;
	char **env=environ;
	while(*env!=NULL)
	{
		printf("%s\n",*env);
		env++;
	}
}

