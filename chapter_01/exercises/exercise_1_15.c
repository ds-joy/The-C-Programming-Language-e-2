#include<stdio.h>

float fahr_to_celsius(int fahr);
int main()
{
	/*
		this program converts farenheit -> celsius
		from fahr 0 to 300 with 20 step size
	*/
	float fahr;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	printf("Farenheit \t Celsius \n");
	while(fahr <= upper)
	{
		printf(" %3.0f  \t\t %6.1f \n", fahr, fahr_to_celsius(fahr));
		fahr = fahr + step;
	}
}

/* 
	this is a function to convert temperature 
  	from Farenheit to Celsius
*/
float fahr_to_celsius(int fahr)
{
	int celsius;
	
	celsius = (5.0/9.0) * (fahr-32.0);

	return celsius;
}



































