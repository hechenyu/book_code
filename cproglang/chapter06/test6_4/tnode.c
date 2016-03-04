/* addtree.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tnode.h"

extern struct tnode *list[];		
extern int ntn;		

/* addtree��������p��λ�û�p���·�����һ��w�ڵ� */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	char *strup(char *);
	struct tnode *talloc(void);
	
	if (p == NULL) {	/* �õ�����һ���µ��� */
		p = talloc();	/* ����һ���½ڵ� */
		p->word = strup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;		/* �µ�����ڵ��еĵ���ƥ�� */
	else if (cond < 0)	/* ���С�ڸýڵ��еĵ��ʣ���������� */
		p->left = addtree(p->left, w);
	else				/* ������ڸýڵ��еĵ��ʣ���������� */
		p->right = addtree(p->right, w);
	return p;
}

/* treestore: store in list[] pointers to tree nodes */
void treestore(struct tnode *p)
{
	if (p != NULL) {
		treestore(p->left);
		if (ntn < NDISTINCT)
			list[ntn++] = p;
		treestore(p->right);
	}
}

/* talloc����������һ��tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strup(char *s)	/* ����s��ĳ��λ��*/
{
	char *p;
	
	p = (char *) malloc(strlen(s)+1);		/* ִ�м�1������Ϊ���ڽ�β�����ַ�'\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}


