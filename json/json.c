#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[50];
    char value[50];
} KeyValuePair;


void parseJson(const char *json) ;

int main() {
    const char *json = "Application";
    
    FILE *file;
    char buffer[1024];

   
    file = fopen("metadata.json", "r");
    if (file == NULL) {
        printf("Failed to open the JSON file.\n");
        return 1;
    }

   
    fread(buffer, sizeof(buffer), 1, file);

  
    fclose(file);

    parseJson(buffer);

    return 0;
}


void parseJson(const char *json) {
    char buffer[100];
    int i = 0;
    int j = 0;

    while (json[i] != '\0') 
    {
        if (json[i] == '{')
        {
           
        printf("start:\n");
        } else if (json[i] == '}') 
        {
            // End of JSON object
            printf("end\n");
        } else if (json[i] == '"') 
        {
            // Start of JSON string
            i++;
            j = 0;
            while (json[i] != '"' && json[i] != '\0')
            {
                buffer[j] = json[i];
                i++;
                j++;
            }
            buffer[j] = '\0';
            printf("Key: %s\n", buffer);
            
            j=0;
        
         while (json[i] != '"' && json[i] != '\0') i++;
         
         
         while (json[i] != '"' && json[i] != '\0')
            {
                buffer[j] = json[i];
                i++;
                j++;
            }
            buffer[j] = '\0';
            printf("Value: %s\n", buffer);
        }

        i++;
    }
}

