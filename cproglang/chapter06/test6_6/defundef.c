/* defundef.c */

#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "defundef.h"

#define		HASHSIZE	101

static struct nlist *hashtab[HASHSIZE];		/* ָ��� */

/* getdef: get definition and install it */
void getdef(void)
{
	int c, i;
	char def[MAXWORD], dir[MAXWORD], name[MAXWORD];
	
	skipblanks();
	if (!isalpha(getword(dir, MAXWORD)))
		error(dir[0],
			"getdef: expecting a directive after #");
	else if (strcmp(dir, "define") == 0) {
		skipblanks();
		if (!isalpha(getword(name, MAXWORD)))
			error(name[0],
				"getdef: non-alpha - name expected");
		else {
			skipblanks();
			for (i = 0; i < MAXWORD-1; i++)
				if ((def[i] = getch()) == EOF ||
					def[i] == '\n')
					break;		/* end of definition */
			def[i] = '\0';
			if (i <= 0)			/* no definition? */
				error('\n', "getdef: incomplete define");
			else
				install(name, def);
		}
	} else if (strcmp(dir, "undef") == 0) {
		skipblanks();
		if (!isalpha(getword(name, MAXWORD)))
			error(name[0], "getdef: non-alpha in undef");
		else
			undef(name);
	} else
		error(dir[0], 
			"getdef: expecting a directive after #");
}

/* error: print error message and skip the rest of the line */
void error(int c, char *s)
{
	printf("error: %s\n", s);
	while (c != EOF && c != '\n')
		c = getch();
}

/* skipblanks: skip blank and tab characters */
void skipblanks(void)
{
	int c;
	
	while ((c = getch()) == ' ' || c == '\t')
		;
	ungetch(c);
}
			
/* undef: remove a name and definition from the table */
void undef(char *s)
{
	int h;
	struct nlist *prev, *np;
	
	prev = NULL;
	h = hash(s);			/* hash value of string s */
	for (np = hashtab[h]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0)
			break;
		prev = np;
	}
	if (np != NULL) {		/* found name */
		if (prev == NULL)	/* first in the hash list? */
			hashtab[h] = np->next;
		else				/* elsewhere in the hash list */
			prev->next = np->next;	
		free((void *) np->name);
		free((void *) np->defn);
		free((void *) np);	/* free allocated structure */
	}
}

/* install��������(name, defn)���뵽hashtab�� */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	
	if ((np = lookup(name)) == NULL) {		/* δ�ҵ� */
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else		/* �Ѵ��� */
		free((void *) np->defn);		/* �ͷ�ǰһ��defn */
	if ((np->defn = strup(defn)) == NULL)
		return NULL;
	return np;
}

/* lookup��������hashtab�в���s */
struct nlist *lookup(char *s)
{
	struct nlist *np;
	
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;		/* �ҵ�s */
	return NULL;		/* δ�ҵ�s */
}

/* hash������Ϊ�ַ���s����ɢ��ֵ */
unsigned hash(char *s)
{
	unsigned hashval;
	
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

char *strup(char *s)	/* ����s��ĳ��λ��*/
{
	char *p;
	
	p = (char *) malloc(strlen(s)+1);		/* ִ�м�1������Ϊ���ڽ�β�����ַ�'\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}


