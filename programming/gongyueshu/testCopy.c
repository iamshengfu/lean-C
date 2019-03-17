#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define digit 300

void print (char* message);

int main(void)
{
    char s[5][5];
    char* x = "abc";
    strcpy(s[0], "12345"); 
    s[3][3] = "abc";
    print((char *)s);
    printf("%c", s[3][3]);
    return 0;
}

void print (char* message) {
            printf("%s", message);
}
