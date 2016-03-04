/* qsortfun.c:  �������� */

#include <stdlib.h>
#include <stdio.h>

#define ARR_LEN 20

/*
 * �˺��������Ƚ�����������Ԫ��
 * �˺�����Ϊsqort()�Ļص�(call-back)����
 * 
 * ����ֵ:  -1����ʾ��һ��Ԫ��С�ڵڶ���Ԫ�أ�
			 0����ʾ������ȣ�
			 1����ʾ��һ��Ԫ�ش��ڵڶ���Ԫ�ء�
 */
int floatcmp( const void* p1, const void* p2 )
{
	float x = *(float*)p1;
	float y = *(float*)p2;

	return (x < y) ? -1 : ((x ==y) ? 0 : 1);
}


/*
 * main()������һ��float�����������
 */
int main()
{
	/* ��̬�ط�������ռ� */
	float* pNumbers = malloc( ARR_LEN * sizeof(float) );

	/* ��ʼ������Ԫ�� */
	float* pTmp = pNumbers;
	float tmp = 25.5;
	int i;
	for (i = 0; i < ARR_LEN / 2; i++) {
		*pTmp = tmp - 2 * i;
		pTmp += 2;
	}

	pTmp = pNumbers + 1;
	for (i = 0; i < ARR_LEN / 2; i++) {
		*pTmp = 2 * i;
		pTmp += 2;
	}

	/* ��ӡ����Ԫ�� */
	pTmp = pNumbers;
	puts("��ʼ������ַ���");
	for (i = 0; i < ARR_LEN; i++) {
		printf("%4.2f\t", *pTmp);
		pTmp++;
		if ((i + 1) % 5 == 0)
			printf("\n");
	}

	/* �������� */
	/* qsort����
	 * ��һ�������������
	 * �ԡ������Ĵ��򡱶������������
	 * ��array�ĵ�ַ��ʼ��ʹ�ÿ��������㷨
	 * ���������n��Ԫ�أ�ÿ��Ԫ�صĿռ��СΪelement_size
	 * ���ĸ�����(compare)ָ��һ�����ȽϺ���������������Ԫ�صıȽ�
	 * ���Ƚϵ�����Ԫ�صĵ�ַ������ָ������ķ�ʽ����ñȽϺ�����
	 * ͨ���ñȽϺ��������ɳ���Ԫ�����ж��塣�����뷵��һ��
	   ֵ��С��0������0�������0���ֱ��ʾ��һ��Ԫ��С�ڡ���
	   �ڣ�����ڵڶ���Ԫ��
	 * void qsort( void *array, size_t n, size_t element_size, 
				   int ( *compare )(const void *, const void *) );
	 */
	qsort( pNumbers, ARR_LEN, sizeof(float), floatcmp );

	/* ��ӡ����Ԫ�� */
	pTmp = pNumbers;
	puts("\nquick�������ַ���");
	for (i = 0; i < ARR_LEN; i++) {
		printf("%4.2f\t", *pTmp);
		pTmp++;
		if ((i + 1) % 5 == 0)
			printf("\n");
	}

	printf("\n");
	return 0;
}
