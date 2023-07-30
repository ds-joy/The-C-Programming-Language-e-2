/*
	Write a function rightrot(x,n) that returns the value of the integer x rotated
	to the right by n positions.
*/


#include<stdio.h>

unsigned rightrot(unsigned x, unsigned n); 
int lenx(unsigned x);
void output(unsigned n, char c);
void print_bits(unsigned n);


int main()
{
    unsigned x, n; 
	x = 0xccccccff;
	n = 2;

	output(x, 'X');
	output(rightrot(x,n), 'R');
	return 0;
}

/* rightrot: returns the value of integer x rotated to the right by n positions */
unsigned rightrot(unsigned x,unsigned n)
{
	unsigned mask1, mask2;
	int len;

	len = lenx(x);

	/*
		to rotate n bits to the right:
		
		1. shift right x, n times
		2. shift left x, (bit_length - n)
		3. logical or of this two operations will
		   rotate x n bits to the right
	*/
	mask1 = x >> n;
	mask2 = x << len-n;

	x = mask1 | mask2;

	return x;
}

/* lenx: returns the bit length of x */
int lenx(unsigned x)
{
	int len;
	len = 0;
	
	while(x) {
		len++;
		x >>= 1;
	}
	
	return len;
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
































