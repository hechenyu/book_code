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

/* bitcount: count 1 bits in x - faster version */
int bitcount(unsigned x)
{
	int b;
	
	for (b = 0; x !=0; x &= x - 1)
		b++;
	return b;
} 
