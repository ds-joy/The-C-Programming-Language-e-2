#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct treeNode {
	char *word;
	int count;
	struct treeNode *left;
	struct treeNode *right;
};

struct key {
	char *word;
	int count;
} keytab[] = { 
		 "_Alignas", 0 ,	 "_Alignof", 0 ,	 "_Atomic", 0 ,			
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

#define MAXWORD 1024
#define BUFSIZE 100
#define DEFAULT_NUM_CHARS 6
#define NKEYS (int)(sizeof keytab / sizeof keytab[0])

enum statusType { NORMAL, STRING, SINGLE_LINE_COMMENT, MULTI_LINE_COMMENT, PREPROCESSOR};
enum boolean { FALSE, TRUE };

char prevChar = '\0';
int type;
int numChars = DEFAULT_NUM_CHARS;





struct treeNode *addtree(struct treeNode *p, char *word);
int binsearch(char *word);
void treeprint(struct treeNode *p, struct treeNode *root);

struct treeNode *talloc(void);
char *mystrdup(char *s);

int getch(void);
void ungetch(int c);


int getword(char *word, int lim);



int main(int argc, char *argv[])

{
	if(argc <= 2) {
		while(--argc > 0)
			if(**++argv == '-' && isdigit(*++*argv))
				numChars = atoi(*argv);
			else 
				argc = -1;
	}

	if(argc != 0) {
		printf("USAGE: getvars [-#]");
		return 1;
	}
	
	if(numChars == 0) {
		printf("ERROR: zero is not a valid number!");
		return 1;
	}

	struct treeNode *root;
	char word[MAXWORD];
	char toAdd[MAXWORD];
	root = NULL;

	toAdd[0] = '\0'; 
	while (getword(word, MAXWORD) != '$') {
        if (word[0] == '"')
        {
            if (type == NORMAL && prevChar != '\'')
                type = STRING;
            else if (type == STRING)
                type = NORMAL;
        }
        else if (word[0] == '/')
        {
            if (prevChar == '/' && type == NORMAL)
                type = SINGLE_LINE_COMMENT;
            else if (type == MULTI_LINE_COMMENT && prevChar == '*')
                type = NORMAL;
        }
        else if (word[0] == '\n' && (type == SINGLE_LINE_COMMENT || type == PREPROCESSOR))
            type = NORMAL;
        else if (word[0] == '*' && prevChar == '/' && type == NORMAL)
            type = MULTI_LINE_COMMENT;
        else if (word[0] == '#' && (prevChar == '\n' || prevChar == '\0')) 
            type = PREPROCESSOR;

        if (strlen(toAdd) > 0 && word[0] != '(') 
            root = addtree(root, toAdd);
        toAdd[0] = '\0'; 
        if (type == NORMAL && (isalpha(word[0]) || word[0] == '_') && binsearch(word) == -1) 
            strcpy(toAdd, word); 
        if (type == PREPROCESSOR && prevChar == '#' && strcmp(word, "define") == 0) 
            type = NORMAL;                                                         
        if (strlen(word) == 1)
            prevChar = word[0]; 
    }
    if (strlen(toAdd) > 0) 
        root = addtree(root, toAdd);
    treeprint(root, root);
    return 0;
}

/* addtree: add a node with word, at or below p */
struct treeNode *addtree(struct treeNode *p, char * word)
{	
	int comp;
	if(p == NULL) {
		p = talloc(); /* make a new node */
		p->word = mystrdup(word);
		p->left = p->right = NULL;
	}
	else if(comp = strcmp(word, p->word) < 0)
		p->left = addtree(p->left, word);
	else if(comp > 0)
		p->right = addtree(p->right, word);
	return p;	/* repeated word */
}










/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c;
	char *w = word;

	while((c = getch()) == '\t' || c == ' ')
		;

	if(c != '$')
		*w++  = c;

	if(!isalpha(c) && c != '_') {
		*w = '\0';
		return c;
	}

	for( ; --lim > 0; w++)
		if( !isalnum(*w = getch()) && *w != '-') {
			ungetch(*w);
			break;
		}

	*w = '\0';
	return w[0];
}













/* binsearch: find word in tab[0] .... tab[n-1], tab[] must be in alphabetical order */
int binsearch(char *word)
{
	int comp, low, mid, high;

	low = 0;
	high = NKEYS - 1;
	

	while(low <= high) {
		mid = (low + high) / 2;

		if((comp = strcmp(word, keytab[mid].word)) < 0)
			high = mid - 1;

		else if(comp > 0)
			low  = mid + 1;

		else
			return mid;
	}
	return -1;
}













/* talloc: allocates memory for new treeNode */
struct treeNode *talloc(void)
{
	return (struct treeNode *) malloc(sizeof(struct treeNode));
}











/* mystrdup: make a duplicate of s, with new memory address */
char *mystrdup(char *s)
{
	char *p = (char *) malloc(strlen(s) + 1);

	if(p != NULL)
		strcpy(p, s);
	
	return p;
}













/* print_tree: in-order print of tree root */
void treeprint(struct treeNode *p, struct treeNode *root)
{
    static char prevWord[MAXWORD] = { '\0' }; 
    static int printPrev = FALSE; 
    if (p != NULL)
    {
        treeprint(p->left, root); 
        if (strncmp(p->word, prevWord, numChars) == 0) 
        {
            printf("%s\n", prevWord);
            printPrev = TRUE;
        }
        else if (printPrev) 
        {
            printPrev = FALSE;
            printf("%s\n\n", prevWord); 
        }
        strcpy(prevWord, p->word); 
        treeprint(p->right, root); 
        if (p == root && printPrev) 
            printf("%s\n", prevWord);
    }
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
		printf("UNGETCH: buffer full!!");
	else
		buf[bufp++] = c;
}















































