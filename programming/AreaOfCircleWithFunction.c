/*------------------------------------------------------*/
/*  Tutorial II.      					*/
/*                                              	*/
/*  This program computes the area of a circle using a 	*/
/*  a function.						*/


#include <stdio.h>
#include <math.h>
#define PI 3.14159
 
int main(void)
{
   /*  Declaration of variables and function prototype.  */
   double  radius,	/* radius of circle */
	   area;	/* area of circle */
   double area_of_circle(double r); /* function declaration	 

   /* Prompt user for input. */
   printf("Enter the radius of the circle (in meter): ");
   scanf("%lf", &radius);

   /*  Call the function to compute the area. */
   area = area_of_circle(radius);

   /*  Print area.  */
   printf("The area of the circle is: %f m^2. \n", area);

   /*  Exit program.  */
   return 0;
}


/*------------------------------------------------------*/
/* Function to compute the area of a circle.		*/

double area_of_circle(double r)
{
    /* Declare variables. */
    double area;

    /* Compute the area of the circle. */
    area =  PI*r*r;

    /* Return area. */
    return area;
}
/*------------------------------------------------------*/

