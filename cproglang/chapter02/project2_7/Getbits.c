/* Getbits.c ����getbits(x, p, n)����x�д��ұ�����pλ��ʼ������nλ���ֶΡ�
			 ����ٶ����ұߵ�һλ�ǵ�0λ��n��p���Ǻ������ֵ */
			 
#include <stdio.h>

unsigned getbits(unsigned x, int begbit, int numbits);
 
int main(int argc, char *argv[])
{
	unsigned x;
	int beg, num; 
	unsigned sub;
	 
	printf("����һ������: ");
	scanf("%i", &x);
	printf("��������ȡ�õ���ʼλ��λ��: ");
	scanf("%i %i", &beg, &num);
	sub = getbits(x, beg, num);
	printf("�����������Ϊ: %u\n", x); 
	printf("���Ϊ: %u\n", sub);
	
	system("PAUSE");	
	return 0;
}

/* getbits����������x�дӵ�pλ��ʼ��nλ */ 
unsigned getbits(unsigned x, int p, int n) 
{
	return (x >> (p - n + 1)) & ~(~0 << n);
}
