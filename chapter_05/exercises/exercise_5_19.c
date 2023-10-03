#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100

enum tokentype { NAME, PARENS, BRACKETS };
enum boolean { FAlSE, TRUE };

void dcl(void);
void dirdcl(void);
int gettoken(void);
int getch(void);
void ungetch(int);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
char buf[BUFSIZE];
int bufp = 0;


/* convert word description to declaration */
int main()
{
    int type, delay = FALSE;
    char temp[MAXTOKEN];

    while (gettoken() != EOF)
    {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
        {
            if (delay)
            {
                if (type == PARENS || type == BRACKETS)
                    snprintf(temp, sizeof(temp), "(*%s)", out);
                else
                    snprintf(temp, sizeof(temp), "*%s", out);
                strcpy(out, temp);
                delay = FALSE;
            }
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*')
                delay = TRUE;
            else if (type == NAME)
            {
                snprintf(temp, sizeof(temp), "%s %s", token, out);
                strcpy(out, temp);
            }
            else
                printf("invalid input at %s\n", token);
        }
        printf("%s\n", out);
    }
    return 0;
}

int gettoken(void) /* return next token */
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


/* dcl: parse a declarator */
int dcl(void)
{
	int ns;
	for(ns = 0; gettoken() == '*') /* count *'s */
		ns++;

	if(dirdcl() == ERROR)
		return ERROR;

	while(ns-- > 0)
		strcat(out, " pointer to");

	return OK;
}


/* dirdcl: parse a direct declarator */
int dirdcl(void)
{
	int type;
	if(tokentype == '(') {
		if(dcl() == ERROR)
			return ERROR;
		if(tokentype != ')') {
			printf("Error: missing )\n");
			return ERROR;
		}
	}
	else if (tokentype == NAME) // variable name
        strcpy(name, token);
    else {
        printf("error: expected name or (dcl)\n");
        return ERROR;
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    return OK;
}

/* get a (possibly pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}




















































