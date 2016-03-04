/* Itoa.c ������ת��Ϊ�ַ��� */
 
#include <stdio.h>
#include <string.h> 

void itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char *argv[])
{
	const int LEN = 11;
	char numstr[LEN]; 
	int n;
	
	printf("Enter an integer: ");
	scanf("%d", &n);
	printf("n = [%d]\n", n);
	itoa(n, numstr);
	printf("numstr = [%s]\n", numstr);
	 
	system("PAUSE");	
	return 0;
}

/* itoa������������nת��Ϊ�ַ��������浽s�� */
void itoa(int n, char s[])
{
	int i, sign;
	
	if ((sign = n) < 0) 	/* ��¼���� */
		n = -n;			/* ʹn��Ϊ���� */
	i = 0;
	do 							/* �Է����������� */ 
		s[i++] = n % 10 + '0';		/* ȡ��һ������ */
	while ((n /= 10) > 0);		/* ɾ�������� */ 
	if (sign < 0) 
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
 
/* reverse: reverse sring s */
void reverse(char s[])
{
	int c, i, j;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	} 
}
