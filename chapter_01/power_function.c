#include<stdio.h>

/* declaration of power function */
int power(int base, int power);

int main()
{
	int i;

	for(i =1; i<= 10; i++)
		printf("%d %d %d\n", i, power(2,i), power(-3, i));

	return 0;
}

/* definition of power function */

int power(int base, int power) 
{

	int i, p;
	p = 1;

	for(i=1; i<=power; i++)
		p = p * base;

	return p;	
}

































