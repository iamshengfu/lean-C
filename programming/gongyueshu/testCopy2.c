#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define digit 300 


long clong(char c){
    int ai;
    long bi;
    ai = c - 48;
    bi = (long)ai;
    return bi;
}
   
int main() 
{
    char s[digit]= "aaa";
    long nb[digit/4];
    scanf("%s",s);
    int i;
    int j;
    int k;
    char c;
    int ai;
    k=0;
    for(i=0;i<digit;i++){
        if(isdigit(s[i])){
            printf("%c \n", s[i]);
        } else {
            break;
        }     
    }
    //printf("%f", ceil(i/4.0));
    
    for(j=0;j<ceil(i/4.0);j++){
        
        long a1 =0 ,a2 = 0 ,a3 =0 ,a4 = 0;
        
        if(i-1-k*4 >= 0){
            a1 = clong(s[i-1-k*4]);
        }
        if(i-2-k*4 >= 0){
            a2 = clong(s[i-2-k*4]) *10;
        }
        if(i-3-k*4 >= 0){
            a3 = clong(s[i-3-k*4]) *100;
        }
        if(i-4-k*4 >= 0){
            a4 = clong(s[i-4-k*4]) *1000;
        }        
        nb[j] = a1 + a2 + a3 + a4;
        k++;
    }
    
    for(j=ceil(i/4.0)-1;j>=0;j--){
       printf("%ld", nb[j]); 
    }
    
    return 0;
}
