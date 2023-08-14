#include <stdio.h>
#define MAXLINE 1024

void i_to_a(int num, char *s);
int reverse_int(int num);

int main()
{
	char cp[MAXLINE];
	int num;


	printf("Please enter number: ");
	scanf("%d", &num);

	num = reverse_int(num);
	i_to_a(num, cp);

	printf("string: %s\n", cp);

	
	return 0;
}

void i_to_a(int num, char *s)
{
	if(num < 0) {
		*s++ = '-';
		num = -num;
	}

	while(num) {
		*s++ = num % 10 + '0';
		num /= 10;
	}

	*s = '\0';
}

int reverse_int(int num)
{
	int temp, sign;

	temp = 0;
	if(num < 0) {
		sign = -1;
		num = -num;
	}
	else {
		sign = 1;
	}

	while(num) {
		temp = temp*10 + num % 10;
		num /= 10;
	}

	return temp*sign;
}
































