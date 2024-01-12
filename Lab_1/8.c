#include<reg51.h>
#include<absacc.h> 

void delay(unsigned long i){
	unsigned long j, k ; 
	for(j = 0; j < i; ++j){
		for(k = 0; k < 500; ++k);
	}
}


unsigned char Fact(unsigned char n){
	unsigned int i, fact= 1; 
	for( i = 2; i <= n; ++i){
		fact = fact * i ;
	}
	return fact; 
}
void main()
{
	unsigned char n = 5; 
	P0 = 0x00; 
	while(1){
		P0 = n;
		delay(50); 
		P0 = Fact(n); 
		delay(50); 
	}
}