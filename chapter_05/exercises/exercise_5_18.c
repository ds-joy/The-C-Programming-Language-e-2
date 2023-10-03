#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100

enum { NAME, PARENS, BRACKETS };
enum { OK, ERROR };

int dcl(void);
int dirdcl(void);
int gettoken(void);
int getch(void);
void ungetch(int c);


int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
char buf[BUFSIZE];
int bufp = 0;

int main()
{
	while(gettoken() != '$') {
		strcpy(datatype, token); /* first token on the line is the datatype */
		out[0] = '\0';
		if(dcl() == OK && tokentype == '\n') /* parse rest of line and print out if no error */
			printf("%s: %s %s\n", name, out, datatype);
		else {
			if(tokentype != '\n')
				printf("syntax error\n");
			for(int c = '\0'; c != '\n' && c != '$';)
				if( (c = getch()) == '$')
					ungetch(c);
		}
	}
	return 0;
}

/* gettoken: return next token */
int gettoken(void) // return next token
{
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}


// parse a declarator
int dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*'; ) // count *'s
        ns++;
    if (dirdcl() == ERROR)
        return ERROR;
    while (ns-- > 0)
        strcat(out, " pointer to");
    return OK;
}



// parse a direct declarator
int dirdcl(void)
{
    int type;
    if (tokentype == '(') // ( dcl )
    {
        if (dcl() == ERROR)
            return ERROR;
        if (tokentype != ')')
        {
            printf("error: missing )\n");
            return ERROR;
        }
    }
    else if (tokentype == NAME) // variable name
        strcpy(name, token);
    else
    {
        printf("error: expected name or (dcl)\n");
        return ERROR;
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    return OK;
}


// get a (possibly pushed back) character
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


// push character back on input
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}













































