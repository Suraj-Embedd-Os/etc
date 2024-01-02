

#ifndef __DEBUG_H
#define __DEBUG_H

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#include<stdio.h>

#define ENABLE	1
#define DISABLE	0

#define DEBUG 1// define where the file want to use
#define DEBUG_ERROR 1


#define DEBUG_LOG(args ...) if(DEBUG) {fprintf(stderr,args) ;printf("  ---- %s --- %d \n",__FILE__,__LINE__); }

#define DEBUG_ERROR_LOG(args ...) if(DEBUG_ERROR) {perror(args); printf("  ---- %s --- %d ",__FILE__,__LINE__);  }


#ifdef __cplusplus
}
#endif // __cplusplus





#endif

