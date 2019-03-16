#include<stdio.h>
#include<math.h>
int main(void)
{
    double PI,R,x=0.5*sqrt(2),y=0.5*sqrt(2),k,n;
    printf("enter:");
    scanf("%lf",&n);
    for (k=8;k<=pow(2,n);k=k*2)
    {
	y=0.5*sqrt(y*y+(1-x)*(1-x));
        x=sqrt(1-y*y);
    }
    PI=y*pow(2,n);
    printf("PI= %.15f \n",PI);
    printf("%d ",sizeof(double));
	return 0;
}
