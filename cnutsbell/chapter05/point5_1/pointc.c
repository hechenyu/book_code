/* pointc.c:  ָ���������� */

#include <stdio.h>


int main()
{
	double dArr[5] = { 0.0, 1.1, 2.2, 3.3, 4.4 };	/* ��ʼ��һ������ */
	double* dPtr = dArr;		/* ��ʼ��һ��ָ�룬ָ������ĵ�һ��Ԫ�� */

	int i = 0;		/* һ���������� */

	dPtr = dPtr + 1;	/* ��dPtrǰ�����ڶ���Ԫ�� */
	dPtr = 2 + dPtr;	/* ����Ҳ����д�ڼӷ���ǰ�棬����dPtrָ��dArr[3] */

	printf( "%.1f\n", *dPtr );	/* ���dPtr�����õ�Ԫ�� */
	printf( "%.1f\n", *(dPtr - 1) );	/* �����ǰλ��֮ǰ��Ԫ�أ���û���޸�dPtrָ�� */

	i = dPtr - dArr;		/* ���������Ԫ�ص����� */
	printf( "��ǰԪ������i = %d\n", i );

	printf( "\n" );
	return 0;
}