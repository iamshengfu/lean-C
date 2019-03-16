#include<stdio.h>
int main(void)
{
    int x[50];
    int k=0,temp,n=0;
    printf("enter a series of integer:");
    do
    {
	scanf("%d",&x[n]);
	n++;
    }
    while
    (scanf("%d",&x[n])!=0);
loop:;
     if (k==(n-1))
     {
	 for (k=0;k<n;k++)
	 printf("%d \0",x[k]);
     }
     else
     {
    if (x[k]>x[k+1])
    {
	temp=x[k];
	x[k]=x[k+1];
	x[k+1]=temp;
	k=0;
	goto loop;
    }
    else
    {
	k++;
	goto loop;
	
    }
     }
    return 0;
}
