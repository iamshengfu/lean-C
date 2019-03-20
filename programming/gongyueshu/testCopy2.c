#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define digit 300 


long clong(char c){
    long ai;
    long bi;
    ai = c - 48;
    bi = (long)ai;
    return bi;
}

long decompose(char * s,long * nb);
void init_str(char * a, long d);
void init_nb(long * nb, long d);
long * addition(long * a, long * b);
void copyfromto(long * src, long * dst, long len);
long * shortmultiply(long * a, long b);
long * longmultiply(long * a, long * b);
long * shiftleft(long * a, long len, long shiftdistance);
long findlen(long * a);
void printresult(long * a);

long main() 
{
    long * result = malloc(digit/4 * sizeof(long));
	char s1[digit]= "aaa";
    long nb1[digit/4];
	char s2[digit]= "aaa";
    long nb2[digit/4];
	//long carry[digit/4];
    long i1;
	long i2;
    long j;
	
	init_str(s1,digit);
	init_str(s2,digit); 
	
	init_nb(nb1,digit/4);
	init_nb(nb2,digit/4);
	//init_nb(carry,digit/4);
	
	scanf("%s",s1);
	scanf("%s",s2);
	
	i1 = decompose(s1,nb1);
	i2 = decompose(s2,nb2);

	copyfromto(longmultiply(nb1,nb2),result, digit/4);
	printf("\nResult > ");
    printresult(result);
    printf(" <Result");
	
    //for(j=ceil(i1/4.0)-2;j>=0;j--){
    //  prlongf("%ld", nb1[j]); 
    //}
    
    return 0;
}

long decompose(char * s,long * nb){
	
	long i,j,tmp;
	long k = 0;
	long a1 =0 ,a2 = 0 ,a3 =0 ,a4 = 0;
	
	for(i=0;i<digit;i++){
		if(isdigit(s[i])){
			;
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

void init_str(char * a, long d){
	long i;
	for(i=0;i<d;i++){
		a[i] = 's';
	}
}	

void init_nb(long * nb, long d){
	long i;
	for(i=0;i<d;i++){
		nb[i] = 0;
	}
}	

long findlen(long * a){
    long a_len;

    for(a_len=0;a_len<digit/4;a_len++){
        if(a[digit/4-1-a_len] != 0){
            break;
        }
    }

    return digit/4-1-a_len;
}




long * addition(long * a, long * b){
	long j;
	long tmp;
    long carry[digit/4];
    static long result[digit/4];
    init_nb(carry,digit/4);
    init_nb(result,digit/4);
    
	for(j=0; j<digit/4 ; j++){
		
		tmp = a[j] + b [j] + carry[j];
		if(tmp > 9999){
			result[j] = tmp - 10000;
			carry[j+1] = 1;
		} else {
			result[j] = tmp;
		}
	}
    return result;
}

long * shortmultiply(long * a, long b){
    static long result[digit/4];
    long i,len,tmp;
    long carry[digit/4];
    init_nb(result,digit/4);
    init_nb(carry,digit/4);
    for(i=digit/4-1;i>=0;i++){
        if(a[i]==0){
            len = i;
            break;
        }
    }
    for(i=0;i<len;i++){
        tmp = a[i] * b;
        result[i] = tmp%10000;
        carry[i+1]= tmp/10000;
    }
        
    return addition(result, carry);
}

long * longmultiply(long * a, long * b){
    long i;
    long len_b;
    long tmp[digit/4], tmp2[digit/4];    
    static long result[digit/4];
    len_b = findlen(b);
    for(i=0;i<=len_b;i++){
        copyfromto(shortmultiply(shiftleft(a,len_b,i), b[i]),tmp,digit/4);
        copyfromto(addition(tmp,result),result,digit/4);      
    }
    return result;
}

void copyfromto(long * src, long * dst, long len){
    long i;
    for(i=0;i<len;i++){
        dst[i] = src[i];        
    }
}

long * shiftleft(long * a, long len, long shiftdistance){
    if(shiftdistance>0){
        static long tmp[digit/4];
        long i;
        copyfromto(a,tmp,digit/4);
        a[0]=0;

        
        for(i=1;i<=len+5;i++){
            a[i] = tmp[i-1];
        }        
    }
        
    return a;

}

void printresult(long * result){
    long j,tmp = 0;
    long a = findlen(result);
    for(j=a ;j>=0;j--){
        if(result[j]==0){
            printf("0000");
        }else{
            printf("%ld", result[j]);
        }        	
	}
    for(j=0;j<digit/4;j++){
        tmp += result[j];
    }
    if(tmp==0){
        printf("0");
    }
}