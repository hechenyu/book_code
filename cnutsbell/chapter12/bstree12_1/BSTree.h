
#ifndef BSTREE_H
#define BSTREE_H

#include <stdlib.h>

/* ���ڵ�Ľṹ���͵Ķ��� */
typedef struct Node
{
	struct Node *left,		// ָ�����
				*right;		// ���ұߵ��ֽڵ㡣
	size_t size;			// ���ݵĿռ��С��
	char data[];			// ���ݱ���
} Node_t;

typedef const void *GetKeyFunc_t( const void *pData );		// �õ�����Ӧ�����ݡ��ļ�ֵ��

typedef int CmpFunc_t( const void *pKey1, const void *pKey2 );	// �Ƚϡ���Ӧ�����ݡ��ļ�ֵ��

/* ���Ľṹ���͵Ķ��� */
typedef struct  
{
	struct Node *pRoot;		// ָ�����ָ�롣
	CmpFunc_t *cmp;			// �Ƚ�������ֵ��
	GetKeyFunc_t *getKey;	// ������ת���ɼ�ֵ��
} BST_t;

// ��̬�ش���һ���µĶ�������ΪBST_t��������ָ��˶����ָ�롣
BST_t *newBST( CmpFunc_t *cmp, GetKeyFunc_t *getKey );		

// ��̬�ش���һ���µĽڵ㣬��pDataָ������ݸ��Ƶ��½ڵ��У�Ȼ���½ڵ���뵽ָ�������С�
_Bool BST_insert( BST_t *pBST, const void *pData, size_t size );	

// �����������Ƚ�ȷ����pKey������ͬ��ֵ����Ŀ��Ȼ�󷵻�һ����ָ�����Ŀ�ڵ㡱��ָ�롣
const void *BST_search( BST_t *pBST, const void *pKey );

// ɾ����һ�����������ݼ�ֵ���ϡ�pKey���Ľڵ㡣
_Bool BST_erase( BST_t *pBST, const void *pKey );

// ɾ�����е����нڵ㡣
void BST_clear( BST_t *pBST );

int BST_inorder( BST_t *pBST, _Bool (*action)( void *pData ) );

/*
int BST_rev_inorder( BST_t *pBST, _Bool (*action)( void *pData ) );

int BST_preorder( BST_t *pBST, _Bool (*action)( void *pData ) );

int BST_postorder( BST_t *pBST, _Bool (*action)( void *pData ) );
*/

#endif