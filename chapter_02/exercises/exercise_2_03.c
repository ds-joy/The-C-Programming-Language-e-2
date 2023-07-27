#include<stdio.h>
#define MAXLEN 1024

long hex_to_int(char s[]);

int main()
{
	char hex[MAXLEN];

	printf("Please enter the hex number: ");
	scanf("%s", hex);

	
	printf("int: %ld\n", hex_to_int(hex));
	
	return 0;
}

/* hex_to_int: converts s to decimal number */

long hex_to_int(char s[]) 
{
    int i;
	int digit;
	long number;
	int start;

	number = 0;
	if(s[0] == '0') {
		if(s[1] == 'x' || s[1] == 'X')
			start = 2;
		else
			start = 1;
	}
	
	for(i = start; s[i] != '\0'; ++i) {

		if(s[i] >= '0' && s[i] <= '9')
			digit = s[i] - '0';
		
		else if(s[i] >= 'a' && s[i] <= 'f')
			digit = s[i] - 'a' + 10;

		else if(s[i] >= 'A' && s[i] <= 'F')
			digit = s[i] - 'A' + 10;
		
		else {
			printf("Invalid Input\n");
			return -1;
		}

		number = 16 * number + digit;
		
	}

	return number;
}

































