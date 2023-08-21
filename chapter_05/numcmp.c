#include <stdio.h>
#include <stdlib.h>

int numcmp(char *s1, char *s2);

int main()
{
	char s1[5];
	char s2[5];


	printf("Enter first number: ");
	scanf("%s", s1);

	printf("Enter second number: ");
	scanf("%s", s2);

	printf("%d\n", numcmp(s1, s2));
	
}


/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	printf("%lf\n", v1);
	printf("%lf\n", v2);
	
	if(v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else
		return 0;
}


















































