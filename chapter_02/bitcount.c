#include<stdio.h>

int bitcount(unsigned x);
int main()
{ 
	unsigned n;
	int count;

	scanf("%d", &n);

	count = bitcount(n);
	printf("Number of 1's = %d\n", count);

	return 0;
}

/* bitcount: returns the total number of 1-bits in n */
int bitcount(unsigned n)
{
	int count = 0;

	while(n != 0) {
		
		if(n & 1)
			count++;
		n >>= 1;
	}
		
	return count;

}






























