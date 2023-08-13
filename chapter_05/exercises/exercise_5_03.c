#include <stdio.h>


void str_cat(char *str1, char *str2);

int main()
{
	char str1[] = "BDCOM ";
	char str2[] = "BANGLADESH";

	str_cat(str1, str2);

	printf("%s\n", str1);

	return 0;
}


/* str_cat: str2 at the end of str1 */
void str_cat(char *str1, char *str2)
{
	/* reach the end of str1 */
	while( *++str1) ;	

	/* copy str2 at the end of str1 */
	while( (*str1++ = *str2++) ) ;	
}



































