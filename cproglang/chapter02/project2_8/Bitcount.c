/* Bitcount.c ����bitcountͳ�������Ͳ�����ֵΪ1�Ķ�����λ�ĸ��� */ 

#include <stdio.h>

int bitcount(unsigned x); 

int main(int argc, char *argv[])
{
	unsigned x, n; 
	 
	printf("������һ������: ");
	scanf("%i", &x);
	n = bitcount(x); 
	printf("%x(base 16)��Ϊ1��λ��(base 2)Ϊ%d\n", x, n);
	
	system("PAUSE");	
	return 0;
}

/* bitcount������ͳ��x��ֵΪ1�Ķ�����λ�� */
int bitcount(unsigned x)
{
	int b;
	
	for (b = 0; x !=0; x >>= 1)
		if (x & 01)
			b++;
	return b;
} 
