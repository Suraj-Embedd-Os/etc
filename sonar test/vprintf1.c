

#include<stdio.h>
#include<stdarg.h>


void  my_scanf(char *format,...)
{
	
	va_list args;
	
	va_start(args,format);
	vscanf(format,args);
	va_end(args);
}

void buff_write(char * buff,char *format,...)
{
	
	va_list args;
	va_start(args,format);
	vsprintf(buff,format,args);
	va_end(args);
	
}

void my_printf(char *format,...)
{
	va_list args;
	
	va_start(args,format);
	vprintf(format,args);
	va_end(args);
	
}

int main()
{
	//write_t("%d my id \n",5);
	//write_t("%d my id and %s\n",5,"IDS");
	
	//char buff[100];
	
	//buff_write(buff,"%d %s",5,"my_buff");
	int a;
	my_printf("enter number\n");
	my_scanf("%d",&a);
	
	my_printf("%d\n",a);
		
}

