#include <stdio.h>
#define ALLOCSIZE 10000	/* size of available space */

char *alloc(int n);
void afree(char *p);

int main()
{
	char *charp;

	charp = alloc(20);

	free(charp);
	
	return 0;
}

/* alloc: return pointer to n characters */
char *alloc(int n)
{
	if( allocbuf + ALLOCSIZE - allocp >= n) {	/* it fits */
		allocp += n;
		return allocp - n; /* old p */
	}
	else	/* not enough room */
		return 0;
}

/* free storage pointed to by p */
void afree(char *p)
{
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}





















