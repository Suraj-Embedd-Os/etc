#include <stdio.h> 
#include <stdlib.h> 
#include <sys/time.h>
#include <time.h>

struct timeval t;

int main() 
{ 
    int r; 
    t.tv_sec = 0; 
    t.tv_usec= 0; 
    r = settimeofday(&t, NULL); 
    
    if (!r)
    { 
        printf("settimeofday() failed\n");
        exit(1); 
        
    } 
    
    gettimeofday(&t, NULL); 
    printf("sec=%ld usec=%ld\n", t.tv_sec, t.tv_usec); 
    printf("%s", ctime(&t.tv_sec));
    
}
    

