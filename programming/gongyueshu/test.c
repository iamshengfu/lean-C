#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define digit 300

void l_add(char* a, char* b);
int splitstring(char *s, char *ss);
void print (char* message);

int main(void)
{
    long x;
    char s[digit];
    scanf("%s",&s);
    
    printf("%ld",x);
    return 0;
}

int init(char *s){
    
}

void l_add(char* a, char* b){
    int i;
    char aa[digit/5][5];
    char bb[digit/5][5];
    splitstring(a,&aa);
    splitstring(b,&bb);
    for(i=0;i<digit/60;i++){
        printf(aa[59]);
    }
}

int splitstring(char *s, char *ss){
    int i;
    for (i=0;i<digit/5;i++){
        strcpy(ss[digit/5 -1-i], strcat(strcat(strcat(strcat(s[295 - 5 * i],s[296 - 5 * i]),s[297 - 5 * i]),s[298 - 5 * i]),s[299 - 5 * i]));
    }
    return 0;
}

void print (char* message) {
            printf("%s", message);
}