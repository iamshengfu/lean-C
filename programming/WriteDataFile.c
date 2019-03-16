/*----------------------------------------------*/
/*  Tutorial II.				*/
/*						*/
/*  Program to demonstrate how to write a data	*/
/*  file. 					*/

#include <stdio.h>
#define FILENAME "DataSum.dat"


int main(void)
{
    /*  Declare and initialize variables.  */
    int x, y, i;
    FILE *data;
    float str1;
    /*  Open output file.  */
    data = fopen(FILENAME,"w");

    /*  Compute data for output file.  */
    for (i=1; i<=10; i++)
    {
	x = i;
	y = 2 * x + 1;
	/*  Print our data to file.  */
	fprintf(data,"%i %i \n", x, y);
    }

    /*  Close file and exit program.  */
    fclose(data);
    scanf("%f", str1);
    return 0;
}
/*---------------------------------------------------*/


