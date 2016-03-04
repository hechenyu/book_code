/* main.c */

#include <stdio.h>
#include <ctype.h>
#include "tnode.h"

#define MAXWORD	100

int getword(char *, int);

/* ���ʳ���Ƶ�ʵ�ͳ�� */
int main()
{
	struct tnode *root;
	char word[MAXWORD];
	
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}
