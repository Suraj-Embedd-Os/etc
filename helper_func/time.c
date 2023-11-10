
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    
    FILE *p;
    int ch;
    char str[30];
    p = popen("date +%H:%M:%S_%m/%d/%Y","r"); 
    
    if( p == NULL)
    {
        puts("Unable to open process");
        return(1);
    }
    
    fgets(str,20,p);
    
   str[strcspn(str, "\r\n")] = 0;
    
    strcat(str,".txt");
    
    printf("%s ",str);
    pclose(p);

    
    return 0;
}
