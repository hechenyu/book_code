/* Rot.c ��xѭ����λ*/

#include <stdio.h>

enum direct {LEFT = -1, RIGHT = 1};

unsigned rot(unsigned x, int n, enum direct d);
unsigned leftrot(unsigned x, int n);
unsigned rightrot(unsigned x, int n);
int wordlength(void);

int main(int argc, char *argv[])
{
	unsigned x, lrot, rrot;
	int num;
	 
	printf("����һ������: ");
	scanf("%i", &x);
	printf("���������Ϊ%x(base 16)\n", x);
	printf("�����������Ƶ�λ��: ");
	scanf("%d", &num);
	lrot = rot(x, num, LEFT);
	printf("����%dλ�����Ϊ%x(base 16)\n", num, lrot);
	printf("����%dλ�����Ϊ%x(base 16)\n", num, leftrot(x, num));
	printf("�����������Ƶ�λ��: ");
	scanf("%d", &num);
	rrot = rot(x, num, RIGHT);
	printf("����%dλ�����Ϊ%x(base 16)\n", num, rrot);
	printf("����%dλ�����Ϊ%x(base 16)\n", num, rightrot(x, num)); 
		
	system("PAUSE");	
	return 0;
}

/* rot: rotate x to the left or right by n positions */
unsigned rot(unsigned x, int n, enum direct d)
{
	switch (d)
	{
	case LEFT:	
		return leftrot(x, n);
		break;
	case RIGHT:
		return rightrot(x, n);
		break;
	default:
		printf("Error direction");
		exit (1);
	}
}

/* rightrot: rotate x to the left by n positions */
unsigned leftrot(unsigned x, int n)
{
	int lbit;		/* leftmost bit */
	
	while (n-- > 0)
	{
		lbit = (x & 1 << (wordlength() - 1)) >> (wordlength() - 1);
		x <<= 1;	/* shift x 1 position left */
		x |= lbit;	/* complete one rotation */
	}
	return x;
}	

/* rightrot: rotate x to the right by n positions */
unsigned rightrot(unsigned x, int n)
{
	int rbit;		/* rightmost bit */
	
	while (n-- > 0)
	{
		rbit = (x & 1) << (wordlength() - 1);
		x >>= 1;	/* shift x 1 position right */
		x |= rbit;	/* complete one rotation */
	}
	return x;
}

/* wordlength: computes word length of the machine */
int wordlength(void)
{
	int i;
	unsigned v = (unsigned)~0;
	
	for (i = 1; (v >>= 1) > 0; i++)
		;
	return i;
}
	
