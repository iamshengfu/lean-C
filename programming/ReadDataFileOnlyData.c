/*----------------------------------------------*/
/*  Tutorial II.				*/
/*  						*/
/*  Program to demonstrate how to read a data	*/
/*  file containing only data.			*/

#include <stdio.h>
#define FILENAME "velocityProfile3.dat"

int main(void)
{
   /*  Declare and initialize variables.  */
   int n_data_pts=0, i;
   double coord, velocity, sum=0;
   FILE *velProfile;
   
   /*  Open file  */
   velProfile = fopen(FILENAME,"r");

   /*  Check that the file could be read properly  */
   if (velProfile == NULL)
       printf("Error - could not open the file!");
   else   
   {
       /*  Read the number of data points. */ 
       while (fscanf(velProfile,"%lf %lf",&coord,&velocity) == 2)
       {
	   n_data_pts++;
	   sum += velocity;
       }

       /*  Print number of lines and average velocity.  */
       printf("Number of lines: %i \n", n_data_pts);
       printf("Average reading: %g \n", sum/n_data_pts);

       /*  Close file.  */
       fclose(velProfile);
   }

   /*  Exit the program.  */
   return 0;
}
/*---------------------------------------------------*/




