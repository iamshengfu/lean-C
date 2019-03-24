#include <math.h>
#include <stdio.h>
#include <time.h>


int main(void)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    long k = 9999*1123;
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTook %f seconds to execute \n", cpu_time_used);
    return 0;
}