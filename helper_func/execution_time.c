#include <stdio.h>
#include <time.h>

#define EXECUTION_TIME  1

void start_time_cal(clock_t *start_time)
{
    #if EXECUTION_TIME  
    *start_time = clock(); // Record the start time
    #endif
}

void end_time_cal(clock_t *end_time)
{   
        #if EXECUTION_TIME   
       *end_time = clock(); // Record the end time
        #endif
}


double time_difference(clock_t * start_time ,clock_t *end_time )
{
     #if EXECUTION_TIME
       double cpu_time_used = ((double) (*end_time - *start_time)) / CLOCKS_PER_SEC;

        printf("Execution Time: %f seconds\n", cpu_time_used);
        
        return cpu_time_used;
     #endif

}

int main() {
    
    #if EXECUTION_TIME
    clock_t start_time, end_time;
    #endif

    start_time_cal(&start_time); // Record the start time

    // Your code to be measured goes here
    for (int i = 0; i < 1000000; i++) {
        // Some time-consuming operation
    }

   end_time_cal(&end_time);// Record the end time

  
  time_difference(&start_time,&end_time);


    return 0;
}
