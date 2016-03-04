/* setBit.c:  ʹ��λ�Ʋ�������λ���� */

#include <stdio.h>
#include <limits.h>

/* setBit()����
 * ������m��pλ�ã�����Ϊ1
 * ʹ��CHAR_BIT(������limits.h��)����һ���ֽ��ڵ�λ��Ŀ
 * ����ֵ�������µ�λ���룬����λp�Ѿ����úã����p����Ч��λ�ã��򷵻�ԭʼλ����
 */
unsigned int setBit( unsigned int mask, unsigned int p )
{
	if ( p >= CHAR_BIT * sizeof(int) ) 
		return mask;
	else
		return mask | ( 1 << p );
}

/* printBit()����
 * ��intBit�������������
 */
void printBit( unsigned int intBit )
{
	const int arrlen = CHAR_BIT * sizeof(int);

	int i;
	int singleBit;
	for ( i = arrlen - 1; i >= 0; --i ) {
		singleBit = 0;
		singleBit = 0x01 & ( intBit >> i );
		printf( "%d", singleBit );
	}

	printf( "\n" );
}


int main()
{
	unsigned int testmask = 11;
	unsigned int bitset = 7;

	printf( "the testmask is:\n" );
	printBit( testmask );

	testmask = setBit( testmask, bitset );

	printf( "the 7 bit is set, testmask now is:\n" );
	printBit( testmask );

	printf( "\n" );
	return 0;
}