/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#define MaxWords 50
#define MaxLength 11
#define MaxWordBuffer MaxLength+1

void getData(char *,char *,char *);
void insertionSortString(char str[][MaxLength],char mob[][MaxLength],int low,int high);
int binarySearch(char *str,char data[][MaxLength],int low,int high);


int main()
{
    char name[10][MaxLength],mob[10][MaxLength];
    char str[50];
    
    FILE *in=fopen("phone_directory","r");
    
    if(in==NULL)
    {
        printf("Can't open\n");
        exit(-1);
    }
    
     int cnt=0;
    while(fgets(str,50,in)!=NULL)
    {
       
        getData(str,name[cnt],mob[cnt]);
        cnt++;
    }
    
    insertionSortString(name,mob,0,9);
    
    for(int i=0;i<10;i++)
    {
       // printf("%s %s\n",name[i],mob[i]);
    }
    
    for(int i=0;i<10;i++)
    {
        printf("%s %s \n",name[i],mob[binarySearch(name[i],name,0,9)]);
    }
    
   
    return 0;
}

void getData(char *str,char *name,char *mob)
{

    int i=0,j=0,k=0;
    while(str[i]!='\0')
    {
        if(isalpha(str[i]))
        name[j++]=str[i];
        else if(isalnum(str[i]))
        mob[k++]=str[i];
        
        i++;
    }
    name[j]='\0';
    mob[k]='\0';

}

void insertionSortString(char str[][MaxLength],char mob[][MaxLength],int low,int high)
{
    char key[10];
    char mob1[10];
    for(int i=low+1;i<=high;i++)
    {
        strcpy(key,str[i]);
        strcpy(mob1,mob[i]);
        int k=i-1;
        
        while(k>=0 && strcmp(key,str[k])<0)
        {
            strcpy(str[k+1],str[k]);
            strcpy(mob[k+1],mob[k]);
            --k;
        }
        strcpy(str[k+1],key);
        strcpy(mob[k+1],mob1);
    }
}

int binarySearch(char *str,char data[][MaxLength],int low,int high)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        
        if(strcmp(str,data[mid])==0)
        return mid;
        else if(strcmp(str,data[mid])<0)
        high=mid-1;
        else
        low=mid+1;
    }
}
