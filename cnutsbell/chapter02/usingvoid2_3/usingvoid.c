/* usingvoid.c:  ��ʾvoid�������͵��÷� */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* <stdlib.h>ͷ�ļ�
 * �ṩ����ĺ���ԭ��:
 * void srand( unsigned int seed );
 * int rand( void );
 * void* malloc( size_t size );
 * void free( void* ptr );
 * void exit( int status );
 */

enum { ARR_LEN = 100 };


int main()
{
#ifdef TESTCODE
	int i;
	int* pNumbers = malloc( ARR_LEN * sizeof(int) );
#else
	int i,			/* �����ͬ�Ĵ洢�ռ� */
		*pNumbers = malloc( ARR_LEN * sizeof(int) );
#endif

	if ( pNumbers == NULL ) {
		fprintf( stderr, "Insufficient memory.\n" );
		exit(1);
	}

	srand( (unsigned)time(NULL) );		/* ��ʼ��������������� */

	for ( i = 0; i < ARR_LEN; ++i )
		pNumbers[i] = rand() % 10000;	/* �洢ĳЩ����� */

	printf( "\n%d random numbers between 0 and 9999:\n", ARR_LEN );
	for ( i = 0; i < ARR_LEN; ++i ) {	/* ѭ����� */
		printf( "%6d", pNumbers[i] );	/* ÿ��ѭ�����һ������ */
		if ( i % 10 == 9 )				/* ÿʮ��ѭ�����һ�λ����ַ� */
			putchar( '\n' );
	}
	free( pNumbers );		/* �ͷŴ洢�ռ� */

	putchar( '\n' );
	return 0;


}