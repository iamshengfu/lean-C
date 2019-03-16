#include <math.h>
#include <stdio.h>

long long y[5000];
long long getchild(long long x);
int main(void)
{
    long long x;
    long k;
    long long   tmp;
    long z;
    k=0;
    for(z=0;z<5000;z++){
        y[z] = 0;
    }
    scanf("%lld",&x);
    while(1){
        tmp = getchild(x);
        if(tmp==x){y[k]=tmp;break;}
        y[k]=tmp;
        k++;
        x=x/tmp;
    }
    for(z=0;z<5000;z++){
        if(y[z]==0){break;}
        printf("%ld  ", y[z]);
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
