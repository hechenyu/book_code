/* syscall.h */
#include <unistd.h>

typedef long Align;		/* ����long���͵ı߽���� */

union header {		/* ���ͷ�� */
	struct {
		union header *ptr;		/* ���п������е���һ�� */
		unsigned size;			/* ����Ĵ�С */
	} s;
	Align x;		/* ǿ�ƿ�Ķ��� */
};

typedef union header Header;