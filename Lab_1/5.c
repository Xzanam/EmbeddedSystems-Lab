#include <reg51.h>
#include <absacc.h>

void delay(unsigned long k)
{
    unsigned long i, j;
    for (i = 0; i < k; i++)
        for (j = 0; j < 500; j++);
}

void large_small(unsigned char base_addr, unsigned char len, unsigned char *smal, unsigned char* lar);

void main()
{
    unsigned char smal, larg;
    DBYTE[0x50] = 0xD6;
    DBYTE[0x51] = 0xF2;
    DBYTE[0x52] = 0xE4;
    DBYTE[0x53] = 0xA8;
    DBYTE[0x54] = 0xCE;
    DBYTE[0x55] = 0xB9;
    DBYTE[0x56] = 0xFA;
    DBYTE[0x57] = 0xAE;
    DBYTE[0x58] = 0xBA;
    DBYTE[0x59] = 0xCC;

    // Call the function to find the small and large values
    large_small(0x50, 10, &smal, &larg);

    P0 = 0x00;

    while (1)
    {
        P0 = smal;
        delay(20);
        P0 = larg;
        delay(20);
    }
}

// Function definition for large_small
void large_small(unsigned char base_addr, unsigned char len, unsigned char* smal, unsigned char* larg)
{
    unsigned char i;
    *smal = DBYTE[base_addr];
    *larg = DBYTE[base_addr];

    for (i = 0; i < len; i++)
    {
        if (DBYTE[base_addr + i] < *smal)
            *smal = DBYTE[base_addr + i];
        if (DBYTE[base_addr + i] > *larg)
            *larg = DBYTE[base_addr + i];
    }
}