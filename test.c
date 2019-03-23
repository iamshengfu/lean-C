#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define digit 3000 

long * retarray(long *);

int main (void){
    long x[5]={1,2,3,4,5};
    long * ptr;
    long i;
    i=0;
    while(i<1000){
        printf("\na");
        ptr = retarray(x);
        i++;
    }
    

}

long * retarray(long * a){
    static long aa[9] = {1,2,3,4,5,6,7,8,9};
    return aa;
}