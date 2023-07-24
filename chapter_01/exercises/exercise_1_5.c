#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
	/* This program prints the conversion table in 
	reverse order */

	float celsius, fahr;

	

	printf("CELSIUS \t FAHRENHEIT \n");
	for(celsius = UPPER; celsius >= LOWER; celsius = celsius - STEP) 
	{
		fahr = (9.0 / 5.0) * celsius+ 32;

		printf("%3.0f \t\t %6.1f \n", celsius, fahr);
	}
}
