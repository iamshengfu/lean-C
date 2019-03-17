#include <math.h>
#include <stdio.h>


long long getchild(long long x);
int wirtetoy(long long *y, long long x);
int main(void)
{
    long long x;
    long k;
    long long   tmp;
    long z;
    long long y[5000];
    k=0;
    for(z=0;z<5000;z++){
        y[z] = 0;
    }
    scanf("%lld",&x);
    
    wirtetoy(y,x);
    
    for(z=0;z<5000;z++){
        if(y[z]==0){break;}
        printf("%ld  ", y[z]);
    }
    return 0;
}

int wirtetoy(long long *y, long long x){
    long long   tmp;
    long k;
    k=0;
    while(1){
    tmp = getchild(x);
    if(tmp==x){y[k]=tmp;break;}
    y[k]=tmp;
    k++;
    x=x/tmp;
    }
    return 0;
}

long long getchild(long long x){
    long i;
    long long result;
    result = x;
    for(i=2;i<=sqrt(x);i++){
        if(x%i==0){
            result=i;
            break;
            }            
    }
    return result;
}
