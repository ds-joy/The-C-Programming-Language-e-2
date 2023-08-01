#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAXLEN 1024

void modified_itoa(int n, char s[]);
void reverse(char s [ ]);


int main()
{
	char number_string[MAXLEN];
	printf("Number: %d \n", INT_MIN);

	modified_itoa(INT_MIN, number_string);

	printf("String: %s \n", number_string);
	return 0;	
}


/* modified_itoa: converts integers to strings, including the maximum negative integer */
void modified_itoa(int n, char s[])
{
	int i, sign;

	sign = n;

	i = 0;

	do {
		s[i++] = abs(n % 10) + '0';

	} while(n /= 10);

	if(sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
	
}


/* reverse: reverse string s in palce */
void reverse(char s [ ])
{
	int c, i, j;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


























