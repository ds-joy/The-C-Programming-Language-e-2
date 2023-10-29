#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define HASHSIZE 101

struct nlist {		/* table entry */
	struct nlist *next;	/* next entry in chain */
	char *name;	/* defined name */
	char *defn;	/* replacement text */
};

static struct nlist *hashtab[HASHSIZE]; 

struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
char *mystrdup(char *s);
unsigned hash(char *s);
void undef(char *s);

void print_hashtable(void);


int main()
{
	install("apple","2");
	install("mango", "10");
	install("banana", "5");
	install("orange", "3");
	print_hashtable();

	printf("\nRemoving mango\n\n");
	undef("mango");
	print_hashtable();

	return 0;
}


/* form hash value from string s */
unsigned hash(char *s)
{
	unsigned hashval;
	for(hashval = 1; *s!= '\0'; s++)
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
		
	return NULL;	/* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if( (np = lookup(name)) == NULL) {	/* not found */
		np = (struct nlist *) malloc(sizeof(*np));
		if(np == NULL || (np->name = mystrdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else	/* already there */
		free((void *) np->defn);	/* free memory used by previous defn */

	if((np->defn = mystrdup(defn)) == NULL)
		return NULL;

	return np;
}




/* mystrdup: make a duplicate of s */
char *mystrdup(char *s)
{
	char *p = (char *)malloc(strlen(s) + 1);

	if(p != NULL)
		strcpy(p, s);
	
	return p;
}




void undef(char *s)
{
	unsigned hashval = hash(s);

	for(struct nlist *p = hashtab[hashval], *prev = NULL; p != NULL; prev = p, p = p->next)
		if(strcmp(s, p->name) == 0) {
			if(prev == NULL) /* at the beginning */
				hashtab[hashval] = p->next;
			else
				prev->next = p->next;

			free(p->name);
			free(p->defn);
			free(p);
			break;
		}	
}




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










































