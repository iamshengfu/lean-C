#include <stdio.h>
#include <math.h>

int main(void)
{

    /*declare variales*/
    double lineA,/*length of A*/ 
	   lineB,/*length of B*/ 
	   angle;/*angle between the vectors*/
    float sp; /*scalar product*/

    /*user prompt*/
 
    printf("enter the length of vector A:");
 
    scanf("%lf", &lineA);
 
    printf("enter the length of vector B:");
 
    scanf("%lf", &lineB);
 
    printf("enter the angle betweet the two vectors in degrees:");
 
    scanf("%lf", &angle);
 
    /*computation*/
 
    sp=lineA*lineB*cos(angle*3.14159265/180);
 
    /*show answer*/
 
    printf("The scalar product of the two vectors is:%.5f \n", sp);
 return 0;
}
