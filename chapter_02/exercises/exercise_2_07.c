/*
Write a function invert(x,p,n) that returns x 
with the n bits that begin at position p inverted 
(i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

#include<stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n); 
void output(unsigned n, char c);
void print_bits(unsigned n);


int main()
{
	unsigned x, p, n;

	x = 0xfff;
	p = 3;
	n = 4;
	

	output(x,'X');
	
	output(invert(x, p, n), 'R');
	
	return 0;
}

/* inverts n bits of x, starting from position p */
unsigned invert(unsigned x,unsigned p,unsigned n)
{
	unsigned mask;
	
	mask = (~(~0 << n)) << p;
	x = x ^ mask;

	return x;
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






































