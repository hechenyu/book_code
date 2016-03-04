/* average.c:  ָ������ */

#include <stdio.h>

#define ARR_LEN 20

void printFloatArray( const float* array, int length )
{
	int i;
	for (i = 0; i < length; ++i) {
		printf( "%10.8f\t", array[i] );
		if ((i + 1) % 5 == 0)
			printf( "\n" );
	}
}


/* average()��������Ԫ�ص�����ƽ��ֵ 
 * �Ա������������顢���鳤��
 * ����ֵ������Ԫ�ص�����ƽ��ֵ��������double
 */
double average( const float* array, int length )
{
	double sum = 0.0;
	float* end = array + length;

	if (length <= 0)
		return 0.0;

	float* p = 0;
	for (p = array; p < end; ++p) 
		sum += *p;

	return sum / length;	
}


int main()
{
	float array[ARR_LEN] = {0};

	printf( "initial array:\n" );
	printFloatArray( array, ARR_LEN );


	int i;
	for (i = 0; i < ARR_LEN; ++i) {
		array[i] = i;
	}
	
	printf( "assigned array:\n" );
	printFloatArray( array, ARR_LEN );

	float ave_result = 0.0;
	ave_result = average( array, ARR_LEN );
	printf( "average of array is: %10.8f\n", ave_result );

	printf( "\n" );
	return 0;
}