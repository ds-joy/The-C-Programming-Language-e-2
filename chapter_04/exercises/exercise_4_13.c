#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void swap(char str[], int pos1, int pos2);
void recursive_reverse(char str[], int pos1, int pos2);


int main()
{
	char str[MAXLEN];
	int c, i;

	i = 0;

	while( (c = getchar()) != '$' && c != '\n' )
		str[i++] = c;

	recursive_reverse(str, 0, i-1);

	printf("%s\n", str);
	
	return 0;
}


/* recursive_reverse: recursively reverses the string str in place */
void recursive_reverse(char str [ ], int pos1, int pos2)
{
	if( pos1 < pos2 )
		recursive_reverse(str, pos1+1, pos2-1);

	swap(str, pos1, pos2);
}



/* swap: swaps the two characters at pos1 pos2 of string str */
void swap(char str[], int pos1, int pos2)
{
	char temp;

	temp = str[pos1];
	str[pos1] = str[pos2];
	str[pos2] = temp;

}










































