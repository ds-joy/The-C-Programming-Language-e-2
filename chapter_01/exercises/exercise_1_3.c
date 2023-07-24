#include<stdio.h>

int main()
{
	/*
		this program converts farenheit -> celsius
		from fahr 0 to 300 with 20 step size
	*/
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	
    /* Adding a heading above the table */
	printf("Fahrenheit \t Celsius \t \n");
	
	while(fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("  %3.0f \t\t %6.1f \t \n", fahr, celsius);
		fahr = fahr + step;
	}
}

