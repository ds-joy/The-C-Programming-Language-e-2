 #include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 500
#define MAXOUTPUT 5000
#define BUFSIZE MAXTOKEN * 2

enum tokentype { VARIABLE, BRACKETS, STORAGECLASS, TYPEQUALIFIER, TYPESPECIFIER }; 
enum returnstatus { OK, ERROR };
enum boolean { FALSE, TRUE };




int dcl(void);
int dirdcl(void);
int gettoken(void);
int parameters(char *out);





int getch(void);
void ungetch(int c); 
int error(char *msg);
char *saferstrcat(char *dst, const char *str, size_t dstsize);


int tokentype;
char token[MAXTOKEN];
char datatype[MAXTOKEN];
char name[MAXTOKEN];
char out[MAXOUTPUT];
char expectParameter;

int buf[BUFSIZE];
int bufp = 0;

int main()
{
	int c;
	expectParameter = FALSE;
	
	while(gettoken() != '$') {
		processDeclaration();
		for(c = tokentype; c != '\n' && c != '$'; )
			if( (c = getch()) == '$' )
				break;
	}
	return 0;
}

/* dcl: Parse a declarator */
int dcl(void)
{
	int ns;

	for(ns = 0; gettoken() == '*'; ) /* count *'s */
		ns++;

	if(dirdcl() == ERROR)
		return ERROR;
	
	while(ns-- > 0)
		if(saferstrcat(out, " pointer to", MAXOUTPUT) == NULL)
			return error("ERROR: input too large to fit into buffer");

	return OK;
}



/* dirdcl: parse a direct declarator */
int dirdcl(void)
{
	int c;
	
	if(tokentype == '(') {
		if(dcl() == ERROR)                                        
			return ERROR;
		if(tokentype != ')')
			return error("Error: missing )");
	}

	else if(tokentype == VARIABLE) {
		saferstrcat(name, token, MAXTOKEN);
	}

	else
		return error("Error: expected variable name or (dcl)\n");

	while(gettoken() == '(' || tokentype == BRACKETS) {
		if(tokentype == '(') {
			if(parameters(out) == ERROR)	/* found a function. Therefore, parse its parameter */
				return ERROR;
		}
		else {
			if(saferstrcat(out, " array", MAXOUTPUT) == NULL)
				return error("Error: input too large to fit into buffer");
			
			if(saferstrcat(out, token, MAXOUTPUT) == NULL)
				return error("Error: input too large to fit into buffer");
			
			if(saferstrcat(out, " of", MAXOUTPUT) == NULL)
				return error("Error: input too large to fit into buffer");
		}
	}

	return OK;
}


int parameters(char *out)
{
    char declaration[MAXOUTPUT];
	expectParameter = TRUE;
    int parameterCount = 0;

    if (gettoken() == ')') 
    {
        if (saferstrcat(out, " obsolescent non-prototype function declaration with unknown parameters returning", MAXOUTPUT) == NULL)
            return error("Error: input too large to fit into buffer");
        return OK;
    }
    else if (tokentype == TYPESPECIFIER && strcmp(token, "void") == 0) 
    {
        if (gettoken() == ')') 
            expectParameter = FALSE;
        else if (tokentype == ',') 
            return error("Syntax error: functions either can have void * parameters or only a single void parameter");
        else 
            for (int i = strlen(token) - 1; i >= 0; i--)
                ungetch(token[i]); // push unused token back to input in reverse order
            tokentype = TYPESPECIFIER; // reset tokentype since not (void)
            snprintf(token, MAXTOKEN, "%s", "void"); // reset token since not (void)
        
    }
    
    if (saferstrcat(out, " function expecting ##### parameters:", MAXOUTPUT) == NULL)
        return error("Error: input too large to fit into buffer");
    if (expectParameter)
        do
        {
            if (parameterCount++ > 0) // don't call gettoken the first time, but call it each time thereafter
                gettoken();
            if (processDeclaration(declaration, expectParameter) == ERROR)
                return ERROR;
            if (strncmp(declaration, " unnamed parameter ", 19) != 0) // check if declaration starts with string
                if (saferstrcat(out, " parameter ", MAXOUTPUT) == NULL) // if parameter has a name, prefix out first before adding the declaration part
                    return error("Error: input too large to fit into buffer");
            if (saferstrcat(out, declaration, MAXOUTPUT) == NULL)
                return error("Error: input too large to fit into buffer");
        } while (tokentype == ','); // get all comma separated parameters
    if (tokentype == ')') // after getting parameters, next token should be )
    {
        
        char parameterMessage[MAXTOKEN], *p1 = out, *p2 = parameterMessage;
        while (*p1 != '#') 
            snprintf(parameterMessage, MAXTOKEN, "no parameters");
        else if (parameterCount == 1)
            snprintf(parameterMessage, MAXTOKEN, "1 parameter:");
        else
            snprintf(parameterMessage, MAXTOKEN, "%d parameters:", parameterCount);
        while (*p2 != '\0') 
            *p1++ = *p2++;
        for (p2 = p1; *p2++ != ':'; ) 
            ;
        while ((*p1++ = *p2++)) 
            ;
        if (saferstrcat(out, " returning", MAXOUTPUT) == NULL)
            return error("Error: input too large to fit into buffer");
    }
    else
        return error("Error: expected closing parentheses after parameters");
    return OK;
}



/* saferstrcat: concatenates str to end of dst.
				requires null terminated strings, dst buffer size.
				returns null if bad pointer of buffer is full,
				otherwise returns pointer to dst. 
*/
				
char *saferstrcat(char *dst, const char *str, size_t dstsize)
{
	if(dst == NULL || str == NULL) /* if either is null, return null */
		return NULL;

	char *dstStart = dst;	/* keeps track of the base of the string */
	size_t dstLen = strlen(dst);
	size_t strLen = strlen(str);

	if(dstLen + strLen >= dstsize)	/* buffer overflow */
		return NULL;	


	dst += dstLen;
	while((*dst++ = *str++))	/* copy str at the end of dst */
		;
	return dstStart;
}








/* gettoken: returns next token */
int gettoken()






/* getch: get the next char */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: store a char in buffer */
void ungetch(int c)
{
	if(bufp > BUFSIZE)
		printf("UNGETCH: BUFFER FULL!");
	else
		buf[bufp++] = c;
}


/* error: Print error message */
int error(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	return ERROR;
}















































