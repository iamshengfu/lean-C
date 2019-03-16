/*----------------------------------------------*/
/*  Tutorial II.				*/
/*						*/
/*  Program to demonstrate how to read a data	*/
/*  file with a specified number of records.	*/

#include <stdio.h>
#define FILENAME "velocityProfile1.dat"

int main(void)
{
   /*  Declare and initialize variables.  */
   int n_data_pts, i;
   double coord, velocity, sum=0;
   FILE *velProfile;
   
   /*  Open file and read the number of data points.  */
   velProfile = fopen(FILENAME,"r");

   /*  Check that the file could be read properly  */
   if (velProfile == NULL)
       printf("Error - could not open the file!");
   else  
   {
       fscanf(velProfile,"%i",&n_data_pts);

       /*  Read data and compute the average velocity.  */
       for (i=1; i<=n_data_pts; i++)
       {
	   fscanf(velProfile,"%lf %lf", &coord, &velocity);
	   sum += velocity;
       }

       /*  Print number of lines and average velocity.  */
       printf("Number of coordinates: %i \n", n_data_pts);
       printf("Average velocity: %g \n", sum/n_data_pts);

       /*  Close file.  */
       fclose(velProfile);
   }

   /*  Exit program.  */
   return 0;
}
/*---------------------------------------------------*/




