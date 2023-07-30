/*
	Write a function setbits(x,p,n,y) that returns x 
	with the n bits that begin at position p set to the 
	rightmost n bits of y, leaving the other bits unchanged.
*/

#include<stdio.h>

void output(unsigned n, char c);
void print_bits(unsigned n);

int main()
{

	unsigned x, y, p, n;
	x = 0xaa;
	y = 0xff;
	n = 4;
	p = 2;

	unsigned mask, xmask, ymask, result;

	/* necessary masks */
	mask = ~(~0 << n);
	xmask = x & ~(mask << p);
	ymask = y & (mask << p);

	result = xmask | ymask;

	
	/* showing output */
	output(x, 'X');
	output(y, 'Y');
	output(result, 'R');

	
	return 0;
}


/* output: handels output design */
void output(unsigned n, char c)
{
	printf("%c : ", c);
	print_bits(n);
	printf("\n");
}


/* print_bits: returns the bit representation of n */
void print_bits(unsigned n)
{
	if( n>1 ) 
		print_bits(n>>1);

	printf("%d ", n & 1);
}

























