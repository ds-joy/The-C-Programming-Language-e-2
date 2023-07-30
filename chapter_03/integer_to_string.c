#include <stdio.h>
#include <string.h>

#define MAXLEN 1024


void itoa(int n, char s[]);
void reverse(char s[]);
int main()
{
	int num;
	char num_string[MAXLEN];

	printf("Enter number: ");
	scanf("%d", &num);

	itoa(num, num_string);

	printf("string: %s \n", num_string);

	
	return 0;
}

/* reverse: reverse string s */
void reverse(char s [ ])
{
	int i, j;
	char c;

	for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itoa: convert n to characters in s */
void itoa(int n,char s [ ])
{
	int i, sign;

	if( (sign = n) < 0)		/* record sign */
		n = -n;		/* make sign positive */

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ( (n /= 10) > 0);

	if(sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
	
}



































