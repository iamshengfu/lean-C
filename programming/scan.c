#include <stdio.h>
#define FN "velocityProfile3.dat"
int main(void)
{
    double x,y,sum=0;
    int z=1;
    FILE *file;
	file=fopen(FN,"r");
	while (fscanf(file,"%d %d",&x,&y)==2)
	{
	    fscanf(file,"%lf %lf",&x,&y);
	    sum=sum+y;
	    z++;
	}
            printf("average velocity is: %lf",sum/z);
	    fclose (file);
	return 0;
}
