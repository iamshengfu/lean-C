/*------------------------------------------------------*/
/*  Tutorial II.					*/
/*							*/
/*  Program to compute an approximation of pi. Two	*/
/*  different algorithms will be used for this purpose.	*/


#include <stdio.h>
#include <math.h>

int main(void)
{
    int    i,		/* iteration variable for loop 	*/
	   n;		/* number of terms for pi	*/
    double pi = 0.0, 	/* first approximation of pi	*/
	   pi2 = 0.0; 	/* second approximation of pi	*/


    /* Prompt for input on the number of terms to be 	*/
    /* computed for pi.					*/
    printf("Enter the number of terms for the approximation"
	    " of pi (must be larger or equal to 1):");
    scanf("%d", &n);

    /* First method to compute pi. 			*/
    for (i = 1; i <= n; i++)
    {
	if (i % 2)
	    pi += 4.0 / (2.0 * i - 1);  /* Odd term 	*/
	else
	    pi -= 4.0 / (2.0 * i - 1);	/* Even term 	*/
    }
    
    printf("The approximate value of pi for %i term(s) is: %.10f \n", 
	    n, pi);   


    /* Second method to compute pi. 			*/
    for (i = 1; i <=n; i++)
	pi2 += pow(-1,(i-1))* 4.0 / (2.0 * i - 1);

    printf("The approximate value of pi for %i term(s) is: %.10f \n", 
	    n, pi2); 


    /* Exit program.  */
    return 0;
} 
/*------------------------------------------------------*/
