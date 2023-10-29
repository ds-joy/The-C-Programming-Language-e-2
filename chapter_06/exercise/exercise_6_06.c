

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define HASHSIZE 101
#define MAXLEN 1024
#define MAXWORD 1024

struct nlist {	/* table entry */
	struct nlist *next;	/* next entry in chain */
	char *name;	/* defined name */
	char *defn; /* replacement value */
};

static struct nlist *hashtab[HASHSIZE];



unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
char *mystrdup(char * s);
void print_hashtable(void);
int get_line(char *s, int lim);


int main()
{
    char line[MAXLEN], name[MAXWORD], defn[MAXWORD], *s;
    int i, len;
    while ((len = get_line(line, MAXLEN)) > 0)
    {
        for (int j = 0; j < len; )
            if (*(s = &line[j]) == '#' && strncmp(s, "#define", 7) == 0) /* found a #define statement */
            {
                j += 7; /* skip #define part */
                while (isspace(line[j]) && j < len) /* skip spaces */
                    j++;
                i = 0;
                while ((isalnum(line[j]) || line[j] == '_') && i < MAXWORD && j < len) /* get name */
                    name[i++] = line[j++];
                name[i] = '\0';
                while (isspace(line[j]) && j < len) /* skip spaces */
                    j++;
                i = 0;
                while (!isspace(line[j]) && i < MAXWORD && j < len) /* get defn */
                    defn[i++] = line[j++];
                defn[i] = '\0';
                install(name, defn); /* add to hashtab */
                break; /* skip rest of line */
            }
            else if (isalpha(line[j]) || line[j] == '_') /* possibly the #define identifier, so check! */
            {
                i = 0;
                while ((isalnum(line[j]) || line[j] == '_') && i < MAXWORD && j < len) /* get the next word */
                    name[i++] = line[j++];
                name[i] = '\0';
                struct nlist *result = lookup(name); /* check to see if in hashtab */
                if (result != NULL) /* if it is, print defn */
                    printf("%s", result->defn);
                else /* otherwise, print word */
					
                    printf("%s", name);
            }
            else /* print everything else */
                putchar(line[j++]);
    }
	
    return 0;
}



/* form hash value from string s */
unsigned hash(char *s)
{
	unsigned hashval;
	for(hashval = 1; *s != '\0'; s++)
		hashval = *s + 31 * hashval;

	return hashval % HASHSIZE;
}





/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for(np = hashtab[hash(s)]; np != NULL; np = np->next)
		if(strcmp(s, np->name) == 0)
			return np;	/* found */

	return NULL; /* not found */
}



/* install: put name, defn in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if((np = lookup(name)) == NULL) {	/* not found */
		np = (struct nlist *) malloc(sizeof(*np));

		if(np == NULL || (np->name = mystrdup(name)) == NULL)
			return NULL;

		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}

	else	/* already there */
		free((void *) np->defn);

	if((np->defn = mystrdup(defn)) == NULL)
		return NULL;

	return np;
}



/* print_hashtable: print the key and value pairs of the hashtable */
void print_hashtable(void)
{
	struct nlist *p;
	for(int i = 0, j = 0; i < HASHSIZE; i++, j = 0) {
		p = hashtab[i];

		while(p != NULL) {
			for(int k = 0; k < j; k++)
				printf("\t");

			printf("%s %s\n", p->name, p->defn);
			p = p->next;
			j++;
		}
	}
}



/* mystrdup: make a duplicate of s */
char *mystrdup(char *s)
{
	char *p = (char *)malloc(strlen(s) + 1);

	if(p != NULL)
		strcpy(p, s);
	
	return p;
}


int get_line(char * s,int lim)
{
	int c, i;

	for(i = 0; (c = getchar()) != '$' && c != '\n'; i++)
		*s++ = c;

	if(c == '\n')
		i++;
	*s = '\0';
	return i;
}














