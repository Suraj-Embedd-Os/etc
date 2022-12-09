#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char ch[10];
	memset(ch,'\0',sizeof(ch));
	while(fgets(ch,sizeof(ch),stdin)!=NULL)
	{
		
		if(strspn(ch,"0123456789.-\n")==strlen(ch))
		{
			printf("%.1f\n",atof(ch)*1.609347);
		}
		else
		{
			fprintf(stderr,"FOUND NON-NUMERIC VALUE\n");
			return 1;
		}
		memset(ch,'\0',sizeof(ch));
	}
	
	
	return 0;
}