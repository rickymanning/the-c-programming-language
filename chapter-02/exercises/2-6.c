/* 2-6 Write a function setbits(x,p,n,y) that returns x with the n bits that
begin at position p set to the rightmost n bits of y, leaving the other bits
unchanged, page 49 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getbits(unsigned x, int p, int n);

int main()
{
    unsigned x, y;
    int p, n;

    x = 209U;
    p = 4;
    n = 3;
    y = 187U;

    printf("%u\n", setbits(x, p, n, y));
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* setbits: replace bits p -> p+1-n of x with rightmost n bits from y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned bits, mask;

    /* get the rightmost n bits from y and shift them to position p */
    bits = getbits(y, n-1, n);
    bits = bits << (p+1-n);

    /* create a mask containing all 1s apart from bits p to p+1-n */
    mask = ~0;
    mask = mask << n;
    mask = (~mask) << (p+1-n);
    mask = ~mask;

    /* mask off the bits in x that we want to overwrite */
    x = x & mask;
    
    /* return the overwritten bits in x */
    return x | bits;
}
