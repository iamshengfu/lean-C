#include <stdio.h>
#include <math.h>
int main(void)
{
    int n;
    double PH[10];
    char Y[10];
    double x[]={1.5e-3,1.9e-9,1.5e-5,1.21e-14,1.3e-6,1.09e-10,1.0001e-7,1.2e-4,1.2e-8,1e-11};
void phcalculation(double x[],double PH[],char Y[]);
phcalculation(x,PH,Y);
    for (n=0;n<=9;n++)
	printf ("%e %.2f %c \n",x[n],PH[n],Y[n]);
		return 0;

}
void phcalculation(double x[],double PH[],char Y[])
{
    int k;
    for (k=0;k<=9;k++)
    {
	PH[k]=-log10(x[k]);
    if
	((PH[k]-7)>0.01)
	Y[k]='B';
    else
	if
	    ((PH[k]-7)<-0.01)
	    Y[k]='A';
	else 
	    Y[k]='N';    
    }
}
