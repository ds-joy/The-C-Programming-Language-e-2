#include <stdio.h>
#include <math.h>

int main()
{
	double value = 180;
	value = (M_PI / 180) * value;
	double ans = sin(value);

	printf("PI = %lf\n", M_PI);

	printf("answer: %lf\n", ans);

	return 0;
}











