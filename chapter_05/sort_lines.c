#include <stdio.h>
#include <string.h>

#define MAXLINES 5000	/* max lines to be sorted */


int read_lines(char *lineptr[], int);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);


char *lineptr[MAXLINES];	/* pointers to the text lines */

/* sort input lines */
int main()
{
	int nlines;	/* number of input lines read */

	if( (nlines = read_lines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return -1;
	}
}



 
/* memory allocation */
#define ALLOCSIZE 100000 /* size of available space */

static char allocbuf[ALLOCSIZE];	/* storage for alloc */
static char *allocp = allocbuf;	/* next free position */

char *alloc(int n)	/* return pointer to n characters */
{
	if(allocbuf + ALLOCSIZE - allocp >= n) {	/* it fits */
		allocp += n;
		return allocp - n; /* old p */
	}	else /* not enough room */
			return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}








#define MAXLEN 1000	/* max lenght of any input line */
int get_line(char *, int);
char *alloc(int);

/* read_lines: read input lines */
int read_lines(char *lineptr[], int a)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines  = 0;
	while( (len = get_line(line, MAXLEN)) > 0)
		if(nlines >= MAXLINES|| (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';  /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}

	return nlines;
}





/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for(i=0; i<nlines; i++)
		printf("%s\n", lineptr[i]);
}



/* qsort: sort v[left].....v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, pivot;
	void swap(char *v[], int i, int j);

	if(left >= right) /* do nothing if array contains fewer than two elements */
		return;

	swap(v, left, (left+right)/2);
	pivot = left;

	for(i = left+1; i <= right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++pivot, i);

	swap(v, left, pivot);
	qsort(v, left, pivot-1);
	qsort(v, pivot+1, right);
}


/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


/* get_line: reads a line of input in s, returns length */
int get_line(char *s, int lim)
{
	int i, c;

	for(i=0; i<lim-1 && (c = getchar()) != '$' && c != '\n'; i++)
		*s++ = c;

	if(c == '\n') {
		*s++ = c;
		i++;
	}

	*s = '\0';
	return i;
}






































