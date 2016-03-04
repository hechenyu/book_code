/* point.c:  ����ָ������η� */

#include <stdio.h>


int main()
{
	int* iPtr = 0;		/* ָ��int��ָ�룬��ʼ��Ϊ0 */
	int iArray[] = { -10, 0, 10, 20 };		/* ��ʼ��һ��int���� */

	int array_length = sizeof(iArray) / sizeof(int);	/* ��ȡԪ�صĸ��� */

	printf( "The array starts at the address %p.\n", iArray );
	*iArray = 5;			/* ����iArray[0] = 5; */

	iPtr = iArray + array_length - 1;	/* ָ��iArray����Ԫ�أ�
										 * �൱��:
										 * iPtr = &iArray[array_length - 1];
										 */

	printf( "The last element of the array is %d.\n", *iPtr );

	return 0;
}