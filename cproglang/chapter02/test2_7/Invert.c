/* Invert.c ����invert(x, p, n)��x�д������pλ(���ұߵ�Ϊ��0λ)��ʼ��
			n��(������)λ�󷴣�x������λ��λ���ֲ��� */
			 
#include <stdio.h>

unsigned getbits(unsigned x, int begbit, int numbits);
unsigned invert(unsigned x, int begbit, int numbits);

int main(int argc, char *argv[])
{
	unsigned x;
	int beg, num; 
	unsigned sub;
	 
	printf("����һ������: ");
	scanf("%i", &x);
	printf("��������ȡ������ʼλ��λ��: ");
	scanf("%i %i", &beg, &num);
	sub = getbits(x, beg, num);
	printf("�����������(base 8)Ϊ: %o\n", x); 
	printf("ȡ�õ�λֵΪ: %o\n", sub);
	sub = invert(x, beg, num);
	printf("ȡ�����ֵΪ: %o\n", sub);
	
	system("PAUSE");	
	return 0;
}

/* getbits����������x�дӵ�pλ��ʼ��nλ */ 
unsigned getbits(unsigned x, int p, int n) 
{
	return (x >> (p - n + 1)) & ~(~0 << n);
}

/* invert: inverts the n bits of x that begin at position p */
unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p - n + 1));
}
