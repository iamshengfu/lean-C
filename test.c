#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define digit 300
#include <time.h>

void testfunction(long * sr,long * des);

int main(void)
{
    long sr[4]={1,2,3,4};
    long des[4]={8,8,6,6};
    
    testfunction(sr,des);
    
    printf("\ndes 1 = %ld", des[3]);
    return 0;
}

void testfunction(long * sr,long * des){

    memcpy(des,sr,4*sizeof(* sr));

}