#include <math.h>
#include <stdio.h>
int main(void)
{
int x,y,z,k;
printf("enter number1:");
scanf("%d",&x);
printf("enter number2:");
scanf("%d",&y);
for (z=y;x%z!=0||y%z!=0;--z);
printf("gong yue shu is:%d\n",z);
for (k=x*(x>y)+y*(y>x);k%x!=0||k%y!=0;k=k+(x*(x>y)+y*(y>x)));
printf("gong bei shu is:%d\n",k);
return 0;
}
