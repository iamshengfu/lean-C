#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int main(void)
{
 /*declaration of vairables*/
 double r, /*radius*/
	l, /*length*/
	area;
/*user prompt*/
printf("Enter the radius of the semi-circle in meter:");
scanf("%lf", &r);
printf("Enter the length in meter:");
scanf("%lf", &l);
/*computation of area*/
area=r*r*PI*0.5+r*2*l;
/*show answer*/
printf("The area is %.4E m^2", area);
return 0;
}
