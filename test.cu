#include<stdio.h>
__global__ void abc(){}

int main(){
    abc<<<1,10>>>();
    printf("hello");
    return 0;
}