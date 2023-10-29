#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct treeNode {
	char *word;
	int count;

	struct treeNode *left;
	struct treeNode *right;
};

char *keywords[] = { 
"_", "a", "about", "above", "after", "again", "against", "ain", "all", "am", "an", "and", "any", "are", "aren", "aren't", "as", "at", "b", "be", "because", "been",
"before", "being", "below", "between", "both", "but", "by", "c", "can", "couldn", "couldn't", "d", "did", "didn", "didn't", "do", "does", "doesn", "doesn't", "doing", 
"don", "don't", "down", "during", "e", "each", "f", "few", "for", "from", "further", "g", "h", "had", "hadn", "hadn't", "has", "hasn", "hasn't", "have", "haven", "haven't", 
"having", "he", "her", "here", "hers", "herself", "him", "himself", "his", "how", "i", "if", "in", "into", "is", "isn", "isn't", "it", "its", "it's", "itself", "j", 
"just", "k", "l", "ll", "m", "ma", "me", "mightn", "mightn't", "more", "most", "mustn", "mustn't", "my", "myself", "n", "needn", "needn't", "no", "nor", "not", "now", "o", 
"of", "off", "on", "once", "only", "or", "other", "our", "ours", "ourselves", "out", "over", "own", "p", "q", "r", "re", "s", "same", "shan", "shan't", "she", "she's", 
"should", "shouldn", "shouldn't", "should've", "so", "some", "such", "t", "than", "that", "that'll", "the", "their", "theirs", "them", "themselves", "then", "there", 
"these", "they", "this", "those", "through", "to", "too", "u", "under", "until", "up", "v", "ve", "very", "w", "was", "wasn", "wasn't", "we", "were", "weren", "weren't", 
"what", "when", "where", "which", "while", "who", "whom", "why", "will", "with", "won", "won't", "wouldn", "wouldn't", "x", "y", "you", "you'd", "you'll", "your", 
"you're", "yours", "yourself", "yourselves", "you've", "z"
};

#define MAXWORD 1024
#define BUFSIZE 1024
#define NKEYS (int) ( sizeof(keywords) / sizeof(keywords[0]) )

int nelements = 0;


struct treeNode *addtree(char *word, struct treeNode *root);
int binsearch(char *word);
void treeprint(struct treeNode *root);

void inorder(struct treeNode *nodes, struct treeNode *root);
int comp(const void *t1, const void *t2);
void inordertobst(struct treeNode *root, struct treeNode nodes[]);
void print_array(struct treeNode nodes[]);


int getword(char *word, int lim);
int getch(void);
void ungetch(int c);

int main()
{
	int c;
	
	char word[MAXWORD];
	struct treeNode *root;
	root = NULL;
	

	struct treeNode nodes[1024];

	while((c = (getword(word, MAXWORD))) != '$') {
		if( isalpha(word[0]) && (c = binsearch(word)) < 0)
			root = addtree(word, root);		
	}
	
	inorder(nodes, root);
	qsort(nodes, nelements, sizeof(struct treeNode), comp);
	
	print_array(nodes);
	//treeprint(root);

	return 0;
}

struct treeNode *talloc(void)
{
	return  (struct treeNode *) malloc(sizeof(struct treeNode)) ;
}

char *mystrdup(char *s)
{
	char *p = (char *) malloc(strlen(s) + 1);

	if(p != NULL)
		strcpy(p, s);

	return p; 
}

struct treeNode *addtree(char *word, struct treeNode *root)
{
	int res;

	if(root == NULL) {
		root = talloc();
		root->word = mystrdup(word);
		root->count++;
		root->left = root->right = NULL;
	}

	if((res = strcmp(word, root->word)) == 0)
		root->count++;
	else if( res < 0)
		root->left = addtree(word, root->left);
	else if(res > 0)
		root->right = addtree(word, root->right);
	
	return root;
}



/* binsearch: */
int binsearch(char *word)
{
	int res, high, low, mid;
	low = 0;
	high = NKEYS - 1;

	while(low <= high) {
		mid = (low + high) / 2;

		if((res = strcmp(word, keywords[mid])) < 0)
			high = mid - 1;
		else if(res > 0)
			low = mid + 1;
		else 
			return mid;
	}
	return -1;
}

/* treeprint: */
void treeprint(struct treeNode *root)
{
	if(root != NULL) {
		treeprint(root->left);
		printf("%s %d\n", root->word, root->count);
		treeprint(root->right);
	}
}




/* getword: read next word or letter from input or buffer */
int getword(char *word, int lim)
{
	int c;
	char *w = word;

	while((c = getch()) == '\t' || c == ' ')
		;

	if(c != '$')
		*w++ = c;

	if(!isalpha(c)) {
		*w = '\0';
		return c;
	}

	for(; --lim > 0; w++) {
		if( !isalpha(*w = getch()) ) {
			ungetch(*w);
			break;
		}
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
		printf("UNGETCH: buffer full");
	else
		buf[bufp++] = c;
}





void inorder(struct treeNode *nodes, struct treeNode *root)
{
	if(root != NULL) {
		inorder(nodes, root->left);
		nodes[nelements++] = *root;
		inorder(nodes, root->right);
	}
}

int comp(const void *t1, const void *t2)
{
	struct treeNode *p1 = (struct treeNode *) t1;
	struct treeNode *p2 = (struct treeNode *) t2;
	           
	return p1->count - p2->count;
}

void inordertobst(struct treeNode *root, struct treeNode nodes[])
{	
	static int i = 0;
	if(root != NULL) {
		inordertobst(root->left, nodes);
		*root = nodes[i++];
		inordertobst(root->right, nodes);
	}
}

void print_array(struct treeNode nodes[])
{
	int i;
	
	for(i = 0; i<nelements; i++)
		printf("%s %d\n", nodes[i].word, nodes[i].count);
}























