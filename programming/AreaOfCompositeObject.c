/*----------------------------------------------*/
/*  Tutorial I     				*/
/*                                              */
/*  This program computes and prints the area 	*/
/*  of the figure by asking for the radius, r,	*/ 
/*  and length, l, in meters.			*/

#include <stdio.h>
#include <math.h>
#define PI 3.141593
 
int main(void)
{
   /*  Declaration of variables  */
   double  radius,	/* radius of circle 	  */
	   length,	/* length of rectangle 	  */
	   area;	/* area of composite body */
    	 

   /* Prompt user for input */
   printf("Enter the radius of the half-circle (in meter): ");
   scanf("%lf", &radius);

   printf("Enter the length of the rectangle (in meter): ");
   scanf("%lf", &length);

   /*  Compute the area of the composite object  */
   area = (PI*radius*radius)/2 + (2*radius*length);

   /*  Print area  */
   printf("The area of the composite object is: %.4e m^2. \n", area);

   /*  Exit program  */
   return 0;
}
/*----------------------------------------------*/


