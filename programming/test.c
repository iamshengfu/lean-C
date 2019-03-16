#include <stdio.h>
#define FILENAME "DataSum.dat"
int main(void)
{
int x, y, i;
FILE *data;
data = fopen(FILENAME,"w");
for (i=1; i<=10; i++)
{
x = i;
y = 2 * x;
fprintf(data,"%i %i \n", x, y);
}
fclose(data);
return 0;
}

