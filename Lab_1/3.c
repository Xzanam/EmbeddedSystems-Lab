#include<reg51.h>
#include<absacc.h> 

void delay(unsigned long i){
	unsigned long j, k ; 
	for(j = 0; j < i; ++j){
		for(k = 0; k < 500; ++k);
	}
}

void main()
{
	unsigned int res = 0; 
	unsigned char i ; 
	DBYTE[0x22]  = 0xFF; 
	DBYTE[0x15] = 0xDE; 
	for( i = 0 ; i < DBYTE[0x15]; ++i ){
		res +=  DBYTE[0x22]; 
	}
	DBYTE[0x19] = res & 0x00FF; 
	DBYTE[0x1A] = (res & 0xFF00) >> 8; 
	while(1){ 
		P0 = DBYTE[0x19]; 
		delay(50);
		P0 = DBYTE[0x1A]; 
		delay(50); 
	}
}