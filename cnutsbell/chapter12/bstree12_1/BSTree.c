
#include <stdlib.h>
#include "BSTree.h"


//*********************************************************************************************
// ��������
//*********************************************************************************************

const void *defaultGetKey( const void *pData )
{
	return pData;
}

BST_t *newBST( CmpFunc_t *cmp, GetKeyFunc_t *getKey )
{
	BST_t *pBST = NULL;
	if ( cmp != NULL )
		pBST = malloc( sizeof(BST_t) );
	if ( pBST != NULL )
	{
		pBST->pRoot = NULL;
		pBST->cmp = cmp;
		pBST->getKey = ( getKey != NULL ) ? getKey : defaultGetKey;
	}
	return pBST;
}


//*********************************************************************************************
// �����½ڵ�
//*********************************************************************************************

static _Bool insert( BST_t *pBST, Node_t **ppNode, const void *pData, size_t size );

_Bool BST_insert( BST_t *pBST, const void *pData, size_t size )
{
	if ( pBST == NULL || pData == NULL || size == 0 )
		return false;
	return insert( pBST, &(pBST->pRoot), pData, size );
}

static _Bool insert( BST_t *pBST, Node_t **ppNode, const void *pData, size_t size )
{
	Node_t *pNode = *ppNode;		// ָ���������ڵ��ָ�룬
									// �µĽڵ�Ҫ����������С�
	if ( pNode == NULL )
	{								// �����Ϊ�µ�Ҷ�ӽڵ����ռ䡣
		pNode = malloc( sizeof(Node_t) + size );
		if ( pNode != NULL )
		{
			pNode->left = pNode->right = NULL;		// ��ʼ���µĽڵ��Ա��
			memcpy( pNode->data, pData, size );
			*ppNode = pNode;						// �����µĽڵ㡣
			return true;
		} 
		else
			return false;
	} 
	else							// �����ҵط�...
	{
		const void *key1 = pBST->getKey( pData ),
				   *key2 = pBST->getKey( pNode->data );
		if ( pBST->cmp( key1, key2 ) < 0 )
			return insert( pBST , &(pNode->left), pData, size );	// ...�������
		else
			return insert( pBST, &(pNode->right), pData, size );	// �����ұ��ҡ�
	}
}


//*********************************************************************************************
// ������������
//*********************************************************************************************

static const void *search( BST_t *pBST, const Node_t *pNode, const void *pKey );

const void *BST_search( BST_t *pBST, const void *pKey )
{
	if ( pBST == NULL || pKey == NULL )
		return NULL;
	return search( pBST, pBST->pRoot, pKey );	// ��������ʼ
}

static const void *search( BST_t *pBST, const Node_t *pNode, const void *pKey )
{
	if ( pNode == NULL )		// û�������ˣ�
		return NULL;			// û���ҵ���
	else
	{							// �Ƚ�����
		int cmp_res = pBST->cmp( pKey, pBST->getKey(pNode->data) );

		if ( cmp_res == 0 )		// Ѱ��ƥ��Ľڵ㡣
			return pNode->data;
		else if ( cmp_res < 0 )							// ��������
			return search( pBST, pNode->left, pKey );	// ����Ѱ�ң�
		else
			return search( pBST, pNode->right, pKey );	// ������������
	}													// ����Ѱ��
}


//*********************************************************************************************
// ������ɾ���ڵ�
//*********************************************************************************************

static Node_t *detachMin( Node_t **ppNode )
{
	Node_t *pNode = *ppNode;					// ָ��Ŀǰ�ڵ��ָ��
	if ( pNode == NULL )
		return NULL;							// pNode��һ���յ�������
	else if ( pNode->left != NULL )
		return datachMin( &(pNode->left) );		// �������е���С��
	else
	{											// pNodeָ����С�ڵ�
		*ppNode = pNode->right;					// �������ӽڵ㵽���ڵ�֮�¡�
		return pNode;
	}
}

static _Bool erase( BST_t *pBST, Node_t **ppNode, const void *pKey );

_Bool BST_erase( BST_t *pBST, const void *pKey )
{
	if ( pBST == NULL || pKey == NULL ) return false;
	return erase( pBST, &(pBST->pRoot), pKey );		// ��������ʼ��
}

static _Bool erase( BST_t *pBST, Node_t **ppNode, const void *pKey )
{
	Node_t *pNode = *ppNode;		// ָ��Ŀǰ�ڵ㡣
	if ( pNode == NULL )			
		return false;				// �Ҳ������ϵĽڵ�

	int cmp_res = pBST->cmp( pKey, pBST->getKey( pNode->data ) );	// �Ƚ����ݣ�

	if ( cmp_res < 0 )									// ����Ѱ��
		return erase( pBST, &(pNode->left), pKey );		// ���������У�
	else if ( cmp_res > 0 )
		return erase( pBST, &(pNode->right), pKey );	// �����������С�
	else
	{											// �ҵ���ɾ���Ľڵ㡣
		if ( pNode->left == NULL )				// ���ֻ��һ����������ӣ�
			*ppNode = pNode->right;				// ���ӽڵ㸽�ӵ����ڵ�֮�¡�
		else if ( pNode->right == NULL )
			*ppNode = pNode->left;
		else								// �����ӽڵ㣺���ұ������е�
		{									// ����Сֵ��ȡ����
			Node_t *pMin = detachMin( &(pNode->right) );
			*ppNode = pMin;					// ����"��ɾ���ڵ�"�ĸ��ڵ㡣
			pMin->left = pNode->left;		// ����"��ɾ���ڵ�"���ӽڵ㡣
			pMin->right = pNode->right;
		}
		free( pNode );					// �ͷű�ɾ���ڵ���ڴ档
		return true;
	}
}

static void clear( Node_t *pNode );

void BST_clear( BST_t *pBST )
{
	if ( pBST != NULL )
	{
		clear( pBST->pRoot );
		pBST->pRoot = NULL;
	}
}

static void clear( Node_t *pNode )
{
	if ( pNode != NULL )
	{
		clear( pNode->left );
		clear( pNode->right );
		free( pNode );
	}
}


//*********************************************************************************************
// �����б���
//*********************************************************************************************

static int inorder( Node_t *pNode, _Bool (*action)( void *pData ) );

int BST_inorder( BST_t *pBST, _Bool (*action)( void *pData ) )
{
	if ( pBST == NULL || action == NULL )
		return 0;
	else
		return inorder( pBST->pRoot, action );
}

static int inorder( Node_t *pNode, _Bool (*action)( void *pData ) )
{
	int count = 0;
	if ( pNode == NULL )
		return 0;
	count = inorder( pNode->left, action );		// L�������������
	if ( action( pNode ->data ) )				// N������Ŀǰ�Ľڵ�
		++count;
	count += inorder( pNode->right, action );	// R�������ұ�������
	return count;
}