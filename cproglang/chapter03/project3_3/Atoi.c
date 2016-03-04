/* Atoi.c ���ַ���ת��Ϊ��Ӧ��ֵ */
 
#include <stdio.h>
#include <ctype.h> 

int atoi(char str[]); 

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

/* atoi��������sת��Ϊ���������汾2 */
int atoi(char s[]) 
{
	int i, n, sign;
	
	for (i = 0; isspace(s[i]); i++)		/* �����հ׷� */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') 	/* �������� */
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}
 

 
