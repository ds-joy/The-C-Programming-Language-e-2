#include<stdio.h>

int main()
{
	/*
		this program converts celsius -> fahrenheit
		from celsius 0 to 300 with 20 step size
	*/
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius= lower;

	
    /* Adding a heading above the table */
	printf("CELSIUS \t FAHRENHEIT \t \n");
	
	while(fahr <= upper)
	{
		fahr= (9.0/5.0) * celsius + 32;
		printf("  %3.0f \t\t %6.1f \t \n", celsius, fahr);
		celsius = celsius + step;
	}
}

