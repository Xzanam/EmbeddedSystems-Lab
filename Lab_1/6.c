#include<reg51.h>
#include<absacc.h> 

void delay(unsigned long i){
	unsigned long j, k ; 
	for(j = 0; j < i; ++j){
		for(k = 0; k < 500; ++k);
	}
}

void sort_asc(unsigned char base_add, unsigned char len)
{
	unsigned char i, j , temp; 
	for( i = 0; i < len ; ++i){
		for( j = 0; j < len; ++j){
			if(DBYTE[base_add + j] < DBYTE[base_add + i]){
				temp = DBYTE[base_add + j]; 
				DBYTE[base_add + j] = DBYTE[base_add + i]; 
				DBYTE[base_add + i] = temp; 
			}
		} 
	}
}

void sort_desc(unsigned char base_add, unsigned char len)
{
	unsigned char i, j , temp; 
	for( i = 0; i < len ; ++i){
		for( j = 0; j < len; ++j){
			if(DBYTE[base_add + j] > DBYTE[base_add + i]){
				temp = DBYTE[base_add + j]; 
				DBYTE[base_add + j] = DBYTE[base_add + i]; 
				DBYTE[base_add + i] = temp; 
			}
		} 
	}
}

void display(unsigned char base_add, unsigned char len){
	unsigned char i ; 
	for( i = 0; i < len; ++i){
		P0 = DBYTE[base_add + i]; 
		delay(50); 
	}
}


void main(){
	DBYTE[0x60] = 0xA5; 
	DBYTE[0x61] = 0xFD; 
	DBYTE[0x62] = 0x67; 
	DBYTE[0x63] = 0x42; 
	DBYTE[0x64] = 0xDF; 
	DBYTE[0x65] = 0x9A; 
	DBYTE[0x66] = 0x84; 
	DBYTE[0x67] = 0x1B; 
	DBYTE[0x68] = 0xC7; 
	DBYTE[0x69] = 0x31; 
	P0 = 0x00;
	while(1){
		sort_asc(0x60, 10); 
		display(0x60, 10); 
		delay(50); 
		sort_desc(0x60, 10); 
		display(0x60, 10); 
		delay(50);		
	}
}