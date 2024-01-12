#include <reg51.h>
#include <absacc.h>
void delay(unsigned long i ){
	unsigned int j, k; 
	for(j = 0; j<i; j++)
		for(k = 0; k < 500; k++);
}


void main()
{
	unsigned long a = 0x00897F9A; 
	unsigned long b = 0x0034BC48;
	unsigned long c = a + b; 
	
	DBYTE[0x40] = ((c)&0x000000FF)>>0; 
	DBYTE[0x41] = ((c)&0x0000FF00)>>8; 
	DBYTE[0x42] = ((c)&0x00FF0000)>>16; 
	P0 = 0x00; 	
	while(1){
		P0 = DBYTE[0x40]; 
		delay(1000); 
		P0 = DBYTE[0x41]; 
		delay(1000); 
		P0 = DBYTE[0x42]; 
		delay(1000); 
	}
}
