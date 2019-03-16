#include <stdio.h>
int main(void)
{
int n = 5;
long factorial_rec(int k);
printf("The factorial of %i! = %li \n",
n, factorial_rec(n));
return 0;
}
long factorial_rec(int k)
{
/* Compute factorial recursively until k=0. */
if (k == 0)
return 1;
else
return k*factorial_rec(k-1);
}

