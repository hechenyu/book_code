/* Atoi.c ���ַ���ת��Ϊ��Ӧ��ֵ */
 
#include <stdio.h>
#include <ctype.h> 

int atoi(char *str); 

int main(int argc, char *argv[])
{
	const int LEN = 11;
	int num;
	char str[LEN];
	
	printf("����һ�������� ");
	scanf("%s", str);
	num = atoi(str); 
	printf("\nstr = %s, and num = %d\n", str, num);
	
	system("PAUSE");	
	return 0;
}

/* atoi: convert s to integer; pointer version */
int atoi(char *s) 
{
	int n, sign;
	
	for ( ; isspace(*s); s++)		/* skip white space */
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-') 	/* �������� */
		s++;
	for (n = 0; isdigit(*s); s++)
		n = 10 * n + (*s - '0');
	return sign * n;
}
 

 
