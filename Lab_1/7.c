#include<reg51.h>
#include<absacc.h> 

void delay(unsigned long i){
	unsigned long j, k ; 
	for(j = 0; j < i; ++j){
		for(k = 0; k < 500; ++k);
	}
}

unsigned char is_prime(unsigned char n){
	unsigned char i; 
	if(n < 2) return 0; 
	if(n == 2) return 1; 
	for(i = 2; i< n -1; ++i){
		if(n % i == 0){return 0; }
	}
	return 1; 
}

unsigned char filter_prime(unsigned char base_add, unsigned char len, unsigned char store_at){
	unsigned char i, j = 0;
	for(i = 0; i < len; ++i){
		if(is_prime(DBYTE[base_add + i])){
			DBYTE[store_at + j] = DBYTE[base_add + i];
			j++; 
		}
	}
	return j; 
}

void main()
{
	unsigned char n_prime;
	unsigned char i; 
	P0= 0x00;
	for(i = 0; i < 0x20; ++i){
		DBYTE[0x40 + i] = i ; 
	}
	n_prime = filter_prime(0x40, 0x20, 0x20); 
	while(1){
		for(i = 0; i < n_prime; ++i){
			P0 = DBYTE[0x20 + i]; 
			delay(50);
		}
	}
	
}