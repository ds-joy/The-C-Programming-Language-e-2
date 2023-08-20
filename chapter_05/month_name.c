#include <stdio.h>

char *month_name(int n);
int main()
{
	int n;

	printf("Please enter month number: ");
	scanf("%d", &n);

	printf("MOnth name: %s\n", month_name(n));


	return 0;
}


char *month_name(int n)
{

	static char *name[] = {
		"Invalid Month!",
			"January",
			"February",
			"March",
			"April",
			"May",
			"June",
			"July",
			"August",
			"September",
			"October",
			"November",
			"December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}












