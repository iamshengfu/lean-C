#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define digit 3000 
#include <time.h>
#define True 1
#define False 0

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
long * shiftleftonce(long * a, long shiftindicator);
long * shiftright(long * a, long shiftdistance);
long findlen(long * a);
void printresult(char * c, long * result);
int compare(long * a, long * b);
long * subtract(long * a, long * b);
long * divisible(long * a, long * b);
long * divide(long * a, long b);
long * lowerb(long * a, long * b);
long * upperb(long * a, long * b);
long isempty(long * a);
long isnearby(long * Ub, long * Lb);
long * mysqrt(long * a);
void findroot(long * a);
long * longdivision(long * a, long * b);

long main() 
{
    clock_t start, end;
    double cpu_time_used;
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
	start = clock();
	i1 = decompose(s1,nb1);
	i2 = decompose(s2,nb2);
    
    //printf("\nisempty %i ",isempty(nb1));
    
    //copyfromto(upperb(nb1,nb2),result,digit/4);
    //findroot(nb1);
    //printf("isempty %i",isempty(nb1));
	//copyfromto(mysqrt(nb1),result, digit/4);
    copyfromto(longdivision(nb1,nb2),result, digit/4);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printresult("\nResult = ",result);
    printf("\nLong Took %f seconds to execute \n", cpu_time_used); 
	start = clock();
    long i;
    for(i=0;i<10000;i++){
        j=99999999/99999;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nShort Took %f seconds to execute \n", cpu_time_used); 
    //printf("%ld", compare(nb1,nb2)); 

    //scanf("%s",s1);
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
	long j,len_a,len_b;
	long tmp;
    long carry=0;
    static long result[digit/4];
    init_nb(result,digit/4);
    len_a = findlen(a);
    len_b = findlen(b);
    if(len_a<len_b){
        len_a = len_b;
    }
	for(j=0; j<=len_a+1 ; j++){
		
		tmp = a[j] + b [j] + carry;
        result[j] = tmp % 10000;
        carry = tmp/10000;

	}
    return result;
}

long * shortmultiply(long * a, long b){
    static long result[digit/4];
    long i,len,tmp;
    long carry[digit/4];
    init_nb(result,digit/4);
    init_nb(carry,digit/4);
    len = findlen(a);
    //printf("\n short multiply len = %ld", len);
    for(i=0;i<=len;i++){
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
    init_nb(tmp,digit/4);
    init_nb(tmp2,digit/4);
    init_nb(result,digit/4);
    copyfromto(a,tmp2,digit/4);
    len_b = findlen(b);
    for(i=0;i<=len_b;i++){
        copyfromto(shortmultiply(shiftleftonce(tmp2,i), b[i]),tmp,digit/4);
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

long * shiftleftonce(long * a, long shiftindicator){
    if(shiftindicator>0){
        static long tmp[digit/4];
        long i,len;
        len =findlen(a);
        copyfromto(a,tmp,digit/4);
        a[0]=0;       
        for(i=1;i<=len+2;i++){
            a[i] = tmp[i-1];
        }        
    }       
    return a;
}

long * shiftright(long * a, long shiftdistance){
    static long tmp[digit/4];
    long i;
    init_nb(tmp,digit/4);

    for(i=0;i<digit/4-shiftdistance;i++){
        tmp[i] = a[i+shiftdistance];
    }
    return tmp;
}

void printresult(char * c, long * result){
    long j,tmp = 0;
    long a = findlen(result);
    printf("%s",c);
    for(j=a ;j>=0;j--){
        if(j!=a){
            if(result[j]==0){
                printf("0000");
            }
            else if(result[j]<10){
                printf("000%ld", result[j]);
            }   
            else if(result[j]<100){
                printf("00%ld", result[j]);
            } 
            else if(result[j]<1000){
                printf("0%ld", result[j]);
            } 
            else{
                printf("%ld", result[j]);
            }
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

int compare(long * a, long * b){
    int L1 = findlen(a);
    int L2 = findlen(b);
    int i;
    if(L1>L2){
        return 0;
    }else if(L2>L1){
        return 1;
    }else if(L2==L1){
        for(i=L1;i>=0;i--){
            if(a[i]>b[i])
            {
                return 0;
            }
            else if(a[i]<b[i]) 
            {
                return 1;
            }
        }
        return 2;
    }
    return -1;
}

long * divisible(long * a, long * b){
    if(compare(a,b)>0){
        static long xxx[digit/4];
        init_nb(xxx,digit/4);
        return xxx;
    }

    static long ret[digit/4];
    init_nb(ret,digit/4);
    long Ub[digit/4];
    long Lb[digit/4];
    long tmp[digit/4];
    static long mid[digit/4];
    long lmt[digit/4];
    long cp,cp1,nearby;
    init_nb(Ub,digit/4);

    init_nb(Lb,digit/4);
    init_nb(tmp,digit/4);
    init_nb(mid,digit/4);
    init_nb(lmt,digit/4);
    copyfromto(upperb(a,b),Ub,digit/4);
    copyfromto(lowerb(a,b),Lb,digit/4);
    
    while(cp1!=2){
        //printresult("\nUb = ", Ub);
        //printresult("\nLb = ", Lb);
        nearby = isnearby(Ub,Lb);
        copyfromto(divide(addition(Ub,Lb),2),mid,digit/4);
        copyfromto(longmultiply(b,mid),lmt,digit/4);
        cp = compare(a,lmt);       
        cp1 = compare(Ub,Lb);
        if(cp1 == 2 && cp != 2){
            return ret;
            //return mid;
        }
        if(cp==2){
            return mid;
        }else if(cp==0){
            if(nearby==1){
                copyfromto(Ub,Lb,digit/4);
            }else{
                copyfromto(mid,Lb,digit/4);
            }
            
            }else if(cp==1){
                if(nearby==1){
                    copyfromto(Lb,Ub,digit/4);
                }else{
                    copyfromto(mid,Ub,digit/4);
                }           
            }
        }
    return ret;
    //return mid;
}

long * longdivision(long * a, long * b){
    if(compare(a,b)==1){
        static long xxx[digit/4];
        init_nb(xxx,digit/4);
        return xxx;
    }
    long iterations =0;
    static long ret[digit/4];
    init_nb(ret,digit/4);
    long one[digit/4];
    long Ub[digit/4];
    long Lb[digit/4];
    long tmp[digit/4];
    long mid[digit/4];
    static long result[digit/4];
    long lmt[digit/4];
    long cp,cp1,nearby;
    init_nb(Ub,digit/4);

    init_nb(Lb,digit/4);
    init_nb(tmp,digit/4);
    init_nb(mid,digit/4);
    init_nb(lmt,digit/4);
    init_nb(one,digit/4);
    init_nb(result,digit/4);
    one[0] = 1;
    cp=0;
    while(1){
        printresult("\n\na = ", a);
        copyfromto(upperb(a,b),Ub,digit/4);
        copyfromto(lowerb(a,b),Lb,digit/4);
        printresult("\nUb = ", Ub);
        printresult("\nLb = ", Lb);
        iterations++;
        printf("\noutside if cp1 == %ld",cp);
        if(cp==0){
            printf("\ncp=0");
            copyfromto(divide(addition(Ub,Lb),2),mid,digit/4);
            copyfromto(addition(result,mid),result,digit/4);
            printresult("\nmid after = ", addition(divide(addition(Ub,Lb),2),mid));
        }else if(cp==1){
            printf("\ncp=1");
            copyfromto(divide(addition(Ub,Lb),2),mid,digit/4);
            copyfromto(subtract(result,mid),result,digit/4);
        }
        
        copyfromto(longmultiply(b,mid),lmt,digit/4);
        cp = compare(a,lmt); 
        printf("\noutside if cp2 == %ld",cp);
        printresult("\nmid = ", mid);  
        printresult("\nlmt = ", lmt);        
        if(cp==2){
            return result;
        }else if(cp==0){
                printf("\nlinex");
                copyfromto(subtract(a,lmt),a,digit/4);
                cp1 = compare(a,b);
                printresult("\nlinx a = ",a);
                printresult("\nlinx b = ",b);
                if(cp1==1){
                    printf("\nline1");
                    return result;
                }else if(cp1==2){
                    copyfromto(addition(result,one),result,digit/4);
                    return result;
                }
        }else if(cp==1){
                printf("\nliney");
                copyfromto(subtract(lmt,a),a,digit/4);
                cp1 = compare(a,b);
                if(cp1==1){
                    printf("\nline2");
                    copyfromto(subtract(result,one),result,digit/4);
                    return result;
                }else if(cp1==2){
                    copyfromto(subtract(result,one),result,digit/4);
                    return result;
                }
            }
        }
        
    //return ret;
    printf("\nIterations = %ld", iterations);
    return result;
}

long isnearby(long * Ub, long * Lb){

    long one[digit/4];
    init_nb(one,digit/4);
    one[0]=1;
    long nn[digit/4];
    copyfromto(addition(Lb,one),nn,digit/4);
    long i;
    for(i=0;i<digit/4;i++){
        if(nn[i]!=Ub[i]){
            return 0;
        }
    }
    return 1;
}


long isempty(long * a){
    long i;
    long z=0;
    for(i=0;i<digit/4;i++){
        if(a[i]!=0){
            return 0;
        }
    }
    return 1;
}

long * upperb(long * a, long * b){
    if(compare(a,b)==1){
        return 0;
    }
    long one[digit/4];
    init_nb(one,digit/4);
    one[0]=1;
    long Lb = findlen(b);
    long tmp[digit/4];
    init_nb(tmp,digit/4);
    static long tmp2[digit/4];
    init_nb(tmp2,digit/4);
    copyfromto(shiftright(a,Lb),tmp,digit/4);
    copyfromto(addition(tmp,one),tmp,digit/4);
    copyfromto(divide(tmp,b[Lb]),tmp2,digit/4);   
    return tmp2;
}

long * lowerb(long * a, long * b){
    if(compare(a,b)==1){
        static long aaa[digit/4];
        init_nb(aaa,digit/4);
        return aaa;
    }
    long Lb = findlen(b);
    //printf("len b = %ld ", Lb);
    long tmp[digit/4];
    init_nb(tmp,digit/4);
    static long tmp2[digit/4];
    init_nb(tmp2,digit/4);
    long bb = b[Lb]+1;
    //printf("long bb = %ld ", bb);
    if(bb!=10000){
        copyfromto(shiftright(a,Lb),tmp,digit/4);   
        copyfromto(divide(tmp,bb),tmp2,digit/4);  
    }else if(bb==10000){
        printf("------------------------------------");
        copyfromto(shiftright(a,Lb+1),tmp2,digit/4); 
    }
    
    return tmp2;
}

long * subtract(long * a, long * b){
    long L1 = findlen(a);
    long L2 = findlen(b);
    long i,tmp;
    static long result[digit/4];
    long carry=0;
    init_nb(result, digit/4);
    if(L1<L2){
        L1 = L2;
    }
    for(i=0;i<=L1;i++){
        tmp = 10000 + carry + a[i] - b [i];
        result[i] = tmp % 10000;
        carry = floor(tmp/10000)-1;
    }
    return result;
}

long * divide(long * a, long b){
    long L1 = findlen(a);
    long i,rmd,tmp;
    rmd=0;
    static long result[digit/4];
    init_nb(result,digit/4);
    for(i=L1;i>=0;i--){
        tmp = a[i] + rmd*10000;
        a[i] = floor(tmp/b);
        rmd = tmp%b;
    }
    return a;
}

long * mysqrt(long * a){
    long len = findlen(a);
    long i;
    long tmp;
    static long result[digit/4];
    init_nb(result,digit/4);
    result[0] = sqrt(a[len])+1;
    if(len>0){
        for(i=0;i<len/2;i++){
            copyfromto(shiftleftonce(result,1),result,digit/4);
        }
        if(len%2==1){
            copyfromto(shortmultiply(result,len%2*100),result,digit/4);
        }
    }
    return result;
}

void findroot(long * a){
    printf("\n start");
    long maxroot[digit/4];
    init_nb(maxroot,digit/4);
    long increment[digit/4];
    init_nb(increment,digit/4);
    long one[digit/4];
    init_nb(one,digit/4);
    long dv[digit/4];
    init_nb(dv,digit/4);
    long * ptr = NULL;
    one[0] = 1;
    increment[0] = 2;
    long increment2[digit/4];
    init_nb(increment2,digit/4);
    increment2[0] = 2;
    copyfromto(mysqrt(a),maxroot,digit/4);
    while(1){
        if(compare(maxroot,increment)==2){
            break;
        }
        ptr = divisible(a,increment);
        if(isempty(ptr)== False){
            printresult("\n child ",increment);
            copyfromto(ptr,a,digit/4);
            copyfromto(increment2,increment,digit/4);
            copyfromto(mysqrt(a),maxroot,digit/4);
        }else{
            copyfromto(addition(increment,one),increment,digit/4);
        }    
    }    
    printresult("\n child ___ ",a);
}