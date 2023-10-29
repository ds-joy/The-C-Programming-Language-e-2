#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct key {
	char *word;
	int count;
} keytab[] = { 
		 "_Alignas", 0 ,		"_Alignof", 0 ,	 "_Atomic", 0 ,			
		 "_Bool", 0 , 		 "_Complex", 0 ,	 "_Generic", 0 ,
		 "_Imaginary", 0 ,	 "_Noreturn", 0 ,  "_Static_assert", 0 ,	
		 "_Thread_local", 0 ,  "auto", 0 ,		 "break", 0 ,
		 "case", 0 ,			 "char", 0 ,		 "const", 0 , 			
		 "continue", 0 ,		 "default", 0 ,	 "do", 0 ,
		 "double", 0 ,		 "else", 0 ,		 "enum", 0 ,				
		 "extern", 0 ,		 "float", 0 , 	 "for", 0 ,
		 "goto", 0 ,			 "if", 0 ,		 "inline", 0 ,			
		 "int", 0 ,			 "long", 0 ,		 "register", 0 ,
		 "restrict", 0 ,		 "return", 0 ,	 "short", 0 , 			
		 "signed", 0 ,		 "sizeof", 0 ,	 "static", 0 ,
		 "struct", 0 ,		 "switch", 0 ,	 "typedef", 0 ,			
		 "union", 0 , 		 "unsigned", 0 ,	 "void", 0 ,
		 "volatile", 0 ,		 "while", 0 
};


#define MAXWORD 100
#define BUFSIZE 1000
#define NKEYS (int)(sizeof keytab / sizeof keytab[0])


int getword(char *, int);
int binsearch(char *, struct key *, int);
int getch(void);
void ungetch(int c);


enum statusTypes { NORMAL, STRING, SINGLE_LINE_COMMENT, MULTI_LINE_COMMENT, PREPROCESSOR };

char prevChar;
int type;



/* count c keywords */
int main()
{
	int n;
	char word[MAXWORD];
	type = NORMAL;
	while(getword(word, MAXWORD) != '$') {

		/* string handle */
		if(word[0] == '"') {
			if(type == NORMAL && prevChar != '\'')
				type = STRING;
			else if(type == STRING)
				type = NORMAL;
		}

		/* handle comment */
		else if(word[0] == '/') {
			if(prevChar== '/' && type == NORMAL)
				type = SINGLE_LINE_COMMENT;
			else if(type == MULTI_LINE_COMMENT && prevChar == '*')
				type = NORMAL;
		}

		/* end of single line comment or preprocessor */
		else if(word[0] == '\n' && (type == SINGLE_LINE_COMMENT || type == PREPROCESSOR))
			type = NORMAL;

		/* start of multiline comment */
		else if(word[0] == '*' && prevChar == '/' && type == NORMAL)
			type = MULTI_LINE_COMMENT;

		/* start of preprocessor */
		else if(word[0] == '#' && prevChar == '\n')
			type = PREPROCESSOR;

		
		else if(type == NORMAL && (isalpha(word[0]) || word[0] == '_'))
			if((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	}

	
	for(n = 0; n < NKEYS; n++)
		if(keytab[n].count > 0)
			printf("%d %s\n", keytab[n].count, keytab[n].word);
	
	return 0;
}



/* binsearch: find word in tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low <= high) {
		mid = (low + high) / 2;
		if( (cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}


/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c;
	char *w = word;

	while(isspace(c = getch()))
		;

	if(c != '$')
		*w++ = c;
	
	if(!isalpha(c) && c!='-') {
		*w = '\0';
		return c;
	}

	for( ; --lim > 0; w++)
		if(!isalnum(*w = getch()) && *w != '-') {
			ungetch(*w);
			break;
		}

	*w = '\0';
	return word[0];
}


char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp > BUFSIZE)
		printf("ungetch: buffer full!");
	else
		buf[bufp++] = c;
}




































































































