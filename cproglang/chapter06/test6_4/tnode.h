/* tnode.h */

#define	NDISTINCT	1000

struct tnode {				/* ���Ľڵ� */
	char *word;				/* ָ�򵥴ʵ�ָ�� */
	int count;				/* ���ʳ��ֵĴ��� */
	struct tnode *left;		/* ���ӽڵ� */
	struct tnode *right;	/* ���ӽڵ� */
};

struct tnode *addtree(struct tnode *, char *);
void treestore(struct tnode *);
