#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define digit 3000 

void printresult(char * c);

int main (void){
    printresult("aaabbbb");
    return 0;
}

void printresult(char * c){
    printf("%s",c);
}