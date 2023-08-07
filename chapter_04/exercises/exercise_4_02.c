#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1024

int get_line(char s [ ],int lim);
double atof(char s[]);


int main()
{
	char line[MAXLEN];
	double ans;

	while(get_line(line, MAXLEN) > 0) {
		ans = atof(line);
		printf("Number: %lf\n", ans);
	}

	return 0;
}


/* atof: convert string s to double */
double atof(char s[])
{

	double val, power;
	int i, sign, exp = 0;

	for(i=0; isspace(s[i]); i++) /* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;

	for(val = 0.0; isdigit(s[i]); i++) 
		val = 10.0 * val + (s[i] - '0');

	if(s[i] == '.')
		i++;

	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}


	
	if(s[i] == 'e' || s[i] == 'E') { 	/* scientific notation check */
		i++;
		
		if(s[i] == '-' || s[i] == '+') { /* scientific notation's sign */
			
			if(s[i] == '-') {	/* 123.45e-6 type case */
				i++;
				exp = s[i] - '0';

				while(exp > 0) {
					power *= 10;
					exp--;
				}
		    }

			else {	/* 123.45e+6 type case */
				i++;
				
				exp = s[i] - '0';
				while(exp > 0) {
					power /= 10;
					exp--;
				}
		    }
		}

		else {		/* 123.45e6 type case */
			
			exp = s[i] - '0';

			while(exp > 0) {
				power /= 10;
				exp--;
			}
		}
 	}

	return sign * val / power;
}


/*get_line: get line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	i = 0;
	while(--lim > 0 && (c = getchar()) != '$' && c != '\n')
		s[i++] = c;

	if(c == '\n')
		s[i++] = c;

	s[i] = '\0';
	return i;
}



































