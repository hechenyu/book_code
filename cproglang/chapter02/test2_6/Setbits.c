/* Setbits.c ����setbits(x, p, n, y)��x�дӵ�pλ��ʼ(����ٶ��ұߵ�һλ�ǵ�0λ)
			 ��n��(������)λ����Ϊy�����ұ�nλ��ֵ��x�������λ���ֲ��䣬����
			 ���ֵ���� */
			  
#include <stdio.h>

unsigned getbits(unsigned x, int begbit, int numbits);
unsigned setbits(unsigned x, int p, int n, unsigned y);
 
int main(int argc, char *argv[])
{
	unsigned x, y;
	int beg, num; 
	unsigned sub;
	 
	printf("����һ������: ");
	scanf("%i", &x);
	printf("��������ȡ�õ���ʼλ��λ��: ");
	scanf("%i %i", &beg, &num);
	sub = getbits(x, beg, num);
	printf("�����������(base 8)Ϊ: %o\n", x); 
	printf("���Ϊ: %o\n", sub);
	printf("�����������õ�ֵ: ");
	scanf("%i", &y);
	sub = setbits(x, beg, num, y);
	printf("���Ϊ: %o\n", sub);
	
	system("PAUSE");	
	return 0;
}

/* getbits����������x�дӵ�pλ��ʼ��nλ */ 
unsigned getbits(unsigned x, int p, int n) 
{
	return (x >> (p - n + 1)) & ~(~0 << n);
}

/* setbits: set n bits of x at position p with bits of y */ 
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return x & ~(~(~0 << n) << (p - n + 1)) |
			(y & ~(~0 << n)) << (p - n + 1);
} 
