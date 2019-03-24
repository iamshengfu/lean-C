#include <math.h>
#include <stdio.h>
#include <time.h>


int main(void)
{
    long a=1;
    a=!a;
    printf("\n%ld",!a);
    a=!a;
    printf("\n%ld",!a);
    a=!a;
    printf("\n%ld",!a);
    return 0;
}