#include<stdio.h>
 #include <unistd.h>

int main()
{
	
	char *arr[10]={ "ls", "-la"};
	
	execlp(arr[0],arr[1],NULL);
	
	printf("hello");
	
}

