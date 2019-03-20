#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define digit 300


int main(void)
{

    printf("%ld", test(0));
    return 0;
}

int test(int a){
    if(a==0){
        return 0;
    }
    return 1;
}