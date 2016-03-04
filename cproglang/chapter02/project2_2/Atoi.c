/* Atoi.c atoi(s)���� */
 
#include <stdio.h>

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

/* atoi���������ַ���sת��Ϊ��Ӧ������ֵ */
int atoi(char s[]) 
{
	int i, n;
	
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
} 
