#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1024

double atof(char s[]);


int main()
{
	char str[MAXLEN];
	double ans;

	printf("Please enter a float number: ");
	scanf("%s", str);

	ans = atof(str);

	printf("Number: %lf\n", ans);
	
	return 0;
}


/* atof: convert string s to double */
double atof(char s[])
{

	double val, power;
	int i, sign;

	for(i=0; isspace(s[i]); i++) /* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;

	for(val = 0.0; isdigit(s[i]); i++) 
		val = 10.0 * val + (s[i] - '0');

	if(s[i] == '.')
		i++;

	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	return sign * val / power;
}

































