#include<stdio.h>
#include<unistd.h>
#include<getopt.h>
#include<stdlib.h>

/* The name of this program */

const char* program_name;

/* Prints usage information for this program to STREAM (typically     
stdout or stderr), and exit the program with EXIT_CODE. Does not     
return.  */ 

void print_usage(FILE* stream,int exit_code)
{
	fprintf(stream,"Usage: %s options [ inputfile .... ]\n",program_name);
	fprintf(stream,
			" -h  --help             Display this usage information.\n"
			" -o  --output filename  write  output to files.\n"
			" -v  --verbose          print verbose message.\n");
	exit(exit_code);
}


int main(int garc,char *argv[])
{
	
	return 0;
}
