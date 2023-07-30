#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1024

int atoi(char s[]);

int main()
{
	char str[MAXLEN];
	int ans;

	scanf("%s", str);
	
	ans = atoi(str);

	printf("Equivalent Number:%d \n", ans);

	return 0;
}


/* atoi: convert char string s to integer */
int atoi(char s[])
{
	int i, n, sign;

	for(i = 0; isspace(s[i]); i++) /* skip white space at the start */
		;

	sign = (s[i] == '-') ? -1 : 1; /* assign sign value */

	if(s[i] == '+' || s[i] == '-') /* skip sign */
		i++;

	for(n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');

	return sign * n;
}



































