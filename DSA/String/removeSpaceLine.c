
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp = fopen("./new","r");
    FILE *fp2 =fopen("./new2","w");
    
    if(fp==NULL)
    {
        perror("fopen");
        exit(-1);
    }
    
   char line[256];
    
 while (fgets(line, sizeof(line), fp) != NULL) {
        // Remove newline character if present
        line[strcspn(line, "\n")] = '\0';
        
        // Skip blank lines
        if (strlen(line) == 1) {
            continue;
        }
        
       fputs(line,fp2);
    }

    return 0;
}
