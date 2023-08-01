#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1024

void itob(int num, char s[], int base);
void reverse(char s [ ]);

int main()
{   
	int num, base;
	char s[MAXLEN];

	printf("Please Enter the number: ");
	scanf("%d", &num);

	printf("Please Enter Base: ");
	scanf("%d", &base);

	itob(num,s,base);

	printf("string: %s \n", s);

	

	return 0;
}


/* itob: converts integer num to base b number */
void itob(int num,char s [ ],int base)
{
	int i, sign, temp;

	sign = num;
	i = 0;

	do {
		temp = abs(num % base);
		if(temp >= 10)
			s[i++] = temp - 10 + 'A';
		else
			s[i++] = temp + '0';
	} while ( abs(num /= base) > 0);

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




























