#include <reg51.h> 

void delay(unsigned long i){
	unsigned long j, k ; 
	for(j = 0; j < i; ++j){
		for(k = 0; k < 500; ++k);
	}
}
unsigned char swap(unsigned char a) {
		unsigned char b = a & 0x0F; 
		a >>=4; 
		return (a | (b << 4)); 
}
	
void main(){
	unsigned char a = 0x6B; 
	P0 = 0x00; 
	while(1){
		P0 = a; 
		a = swap(a) ; 
		delay(20);
		P0 = a; 
	}
}