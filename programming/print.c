#include <stdio.h>
#define DT "data.dat"
int main(void)
{
    FILE *file;
	file=fopen(DT,"w");
	int x=1,y;
	while (x<=10)
	{
	    y=2*x+1;
	    fprintf(file,"%d %d \n",x,y);
		x++;
	}
	fclose (file);
	return 0;
}	
	
