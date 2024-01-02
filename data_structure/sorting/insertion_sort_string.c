#include <stdio.h>
#include<string.h>


void sortString(char name[][15],int low,int high)
{
    char key[15];
   
    
    for(int h=low+1;h<=high;h++)
    {
         strcpy(key,name[h]);
         int k=h-1;
        while(k>=0 && strcmp(key,name[k])<0)
        {
            strcpy(name[k+1],name[k]);
            k--;
        }
       strcpy(name[k+1],key);  
    }
}

int main()
{
   char name[8][15]={"surat","mumbai","delhi","bangalore","kolkata","hello","kashmir","rajasthan"};
   
   sortString(name,0,7);
   
   for(int i=0;i<8;i++)
   printf("%s ",name[i]);

    return 0;
}
