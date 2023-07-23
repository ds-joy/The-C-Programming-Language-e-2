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

	while(fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f \n", fahr, celsius);
		fahr = fahr + step;
	}
}
