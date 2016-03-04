/* tnode.h */

struct tnode {				/* ���Ľڵ� */
	char *word;				/* ָ�򵥴ʵ�ָ�� */
	int count;				/* ���ʳ��ֵĴ��� */
	struct tnode *left;		/* ���ӽڵ� */
	struct tnode *right;	/* ���ӽڵ� */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
