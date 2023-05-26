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


int main(int argc,char *argv[])
{
	int next_option;
	
	/* A string listing valid short option letters */
	
	const char * const short_option="ho:v";
	
	/* An array describing valid long option. */
	
	const struct option long_options[]={
		{"help",0,NULL,'h'},
		{"output",1,NULL,'o'},
		{"verbose",0,NULL,'v'},
		{NULL,0,NULL,0} /* Reguired at the end of array */
		};
		
		/* The name of file to receive program output , or NULL for standard output */
		
		const char * output_filename =NULL;
		
		/* Whether to display verbose message */
		
		int verbose=0;
		
		/* program name sotored in argv[0]*/
		
		program_name=argv[0];
		
		do
		{
			next_option=getopt_long(argc,argv,short_option,long_options,NULL);
			
			switch(next_option)
			{
				case 'h':
				 /* User has requested usage information. Print it to standard        
				 output, and exit with exit code zero (normal termination).  */ 
				print_usage(stdout,0);
				
				case 'O':
				 /* This option takes an argument, the name of the output file.  */ 
				 output_filename = optarg; 
				 break;
				 
				case 'v':
				verbose = 1;
				break;
				
				case '?':
				/* The user specified an invalid option.  */     
				/* Print usage information to standard error, and exit with exit 
				code one (indicating abnormal termination).  */     
				print_usage (stderr, 1); 
				
				case -1: /* Done with the options */
				break ;
				
				default:
				abort();
			}
		}
		while(next_option != -1);
		/* Done with options.  OPTIND points to first nonoption argument.   
		For demonstration purposes, print them if the verbose option was     specified.  */ 
		if (verbose) 
		{     
			int i;     
			for (i = optind; i < argc; ++i)        
				printf ("Argument: %s\n", argv[i]);   
		}  
 
 		
	return 0;
}

