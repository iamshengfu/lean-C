#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define digit 300 


long clong(char c){
    int ai;
    long bi;
    ai = c - 48;
    bi = (long)ai;
    return bi;
}

int decompose(char * s,long * nb);
void init_str(char * a, int d);
void init_nb(long * nb, int d);
void addition(long * a, long * b, long * carry, long * result);
 
int main() 
{
    long result[digit/4];
	char s1[digit]= "aaa";
    long nb1[digit/4];
	char s2[digit]= "aaa";
    long nb2[digit/4];
	long carry[digit/4];
    int i1;
	int i2;
    int j;
	
	init_str(s1,digit);
	init_str(s2,digit);
	init_nb(result,digit/4);
	init_nb(nb1,digit/4);
	init_nb(nb2,digit/4);
	init_nb(carry,digit/4);
	
	scanf("%s",s1);
	scanf("%s",s2);
	
	i1 = decompose(s1,nb1);
	i2 = decompose(s2,nb2);
    
	addition(nb1,nb2,carry,result);
	
	for(j=digit/4-1 ;j>=0;j--){
		if(result[j] != 0){
			printf("%ld", result[j]);
		}		
	}
	
    //for(j=ceil(i1/4.0)-2;j>=0;j--){
    //  printf("%ld", nb1[j]); 
    //}
    
    return 0;
}

int decompose(char * s,long * nb){
	
	int i,j,tmp;
	int k = 0;
	long a1 =0 ,a2 = 0 ,a3 =0 ,a4 = 0;
	
	for(i=0;i<digit;i++){
		if(isdigit(s[i])){
			printf("%c \n", s[i]);
		} else {
			break;
		}     
    }
	
	tmp = i;
	
	for(j=0;j<ceil(i/4.0);j++){
	
		long a1 =0 ,a2 = 0 ,a3 =0 ,a4 = 0;
		
		if(i-1-k*4 >= 0){
			a1 = clong(s[i-1-k*4]);
		}
		if(i-2-k*4 >= 0){
			a2 = clong(s[i-2-k*4]) *10;
		}
		if(i-3-k*4 >= 0){
			a3 = clong(s[i-3-k*4]) *100;
		}
		if(i-4-k*4 >= 0){
			a4 = clong(s[i-4-k*4]) *1000;
		}        
		nb[j] = a1 + a2 + a3 + a4;
		k++;
    }
	
	return tmp;
}

void init_str(char * a, int d){
	int i;
	for(i=0;i<d;i++){
		a[i] = 's';
	}
}	

void init_nb(long * nb, int d){
	int i;
	for(i=0;i<d;i++){
		nb[i] = 0;
	}
}	

void addition(long * a, long * b, long * carry, long * result){
	int j;
	long tmp;
	for(j=0; j<digit/4 ; j++){
		
		tmp = a[j] + b [j] + carry[j];
		if(tmp > 9999){
			result[j] = tmp - 10000;
			carry[j+1] = 1;
		} else {
			result[j] = tmp;
		}
	}			
}