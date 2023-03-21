

#include <sys/time.h>
#include <stdio.h>

#include "getTime.h"


  long long getTimeInusec()
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
    return current_time.tv_usec;
} 



