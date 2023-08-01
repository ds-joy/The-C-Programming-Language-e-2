#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAXLEN 1024

void modified_itoa_v2(int n, char s[], int field_size);
void reverse(char s [ ]);


int main()
{
	char number_string[MAXLEN];
	int num, field_size;
		
	printf("Please enter an integer number: ");
	scanf("%d", &num);
	printf("Number: %d \n", num);

	printf("Please enter field size: ");
	scanf("%d", &field_size);
	

	modified_itoa_v2(num, number_string, field_size);

	printf("String: %s \n", number_string);
	return 0;	
}


/* 
	modified_itoa_v2: 
	converts integers to strings, including the maximum negative integer 
	The third argument is a minimum field width; the converted number
	is padded with blanks on the left if necessary to make it wide enough
*/
void modified_itoa_v2(int n, char s[], int field_size)
{
	int i, sign;

	sign = n;

	i = 0;

	do {
		s[i++] = abs(n % 10) + '0';
	} while(n /= 10);

	if(sign < 0)
		s[i++] = '-';

	while(i < field_size)
		s[i++] = '*'; 	/* for the visualization purpose we have used '*' instead of ' ' */

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








































