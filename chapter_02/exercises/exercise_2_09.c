/* a faster version of bitcount. */

#include<stdio.h>

int faster_bitcount(unsigned n);
void output(unsigned n, char c);
void print_bits(unsigned n);

int main()
{
	unsigned n;
	int count = 0;
	scanf("%u", &n);

	output(n, 'X');
	count = faster_bitcount(n);
	printf("Number of 1's = %d\n", count );
	
	return 0;
}

int faster_bitcount(unsigned n)
{
	int count;

	for(count = 0; n != 0; n &= n-1) {
		// output(n, 'X'); 
		count++;
	}
		

	return count;
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































