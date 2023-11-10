#ifndef LOCK_FILE_H      
#define LOCK_FILE_H       
 
void  set_defaults(int, char *[], int *, int *, char **);      
bool  acquire(int, int, char *);       
bool  release(char *);       
#endif
