#include <stdio.h>
#define MAXLEN 100


void recursive_itoa(int num, char str[]);

int main()
{

	int num;
	char str[MAXLEN];

	
	scanf("%d", &num);

	recursive_itoa(num, str);
	printf("%s\n", str);

	
	return 0;
}


void recursive_itoa(int num, char str[])
{
	static int i = 0;

	if(num < 0) {
		str[i++] = '-';	
		num = -num;
	}

	if(num / 10)
		recursive_itoa(num/10, str);

	str[i++] = num % 10 + '0';
}

