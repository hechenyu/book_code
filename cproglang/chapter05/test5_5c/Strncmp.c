/* Strncmp.c */

#include <stdio.h>

int getline(char line[], int maxline);
int strlen(char *str);
int strcmp(char *str1, char *str2);
int strncmp(char *str1, char *str2, int n);

int main(int argc, char *argv[])
{
	const int LEN = 128; 
	char response;
	char str1[LEN], str2[LEN];
	int result; 
	
	do
	{ 
		printf("�����һ���ַ���(С��128���ַ�), �Իس�����\n");
		getline(str1, LEN);
		printf ("����ڶ����ַ���(С��128���ַ�), �Իس�����\n");
		getline(str2, LEN);
		
		result = strcmp(str1, str2);
		if (result == 0)
			printf("��һ���ַ������ڵڶ����ַ���.\n");
		else 
		{
			int num = strlen(str1);
			int i; 
			for (i = 1; i <= num; i++)
			{
				result = strncmp(str1, str2, i);
				if (result == 0) 
					continue;
				else if (result > 0)
				{
					printf("��һ���ַ������ڵڶ����ַ���, �ڵ�%d���ַ���.\n", i); 
					break;
				}
				else
				{
					printf("��һ���ַ���С�ڵڶ����ַ���, �ڵ�%d���ַ���.\n", i); 
					break;
				}
			}
		}
		
		printf("������? (y/n): ");
		result = getchar();
		while(getchar() != '\n')
			; 
	} 
	while (result != 'n' && result != 'N');
	
	system("PAUSE");	
	return 0;
}

/* strncmp: compare at most n characters of t with s */
int strncmp(char *s, char *t, int n)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0' || --n <= 0)
			return 0;
	return *s - *t;
}

/* strcmp����������s�����ֵ�˳��С�ڡ����ڻ����t�Ľ���ֱ𷵻ظ�������0
			   �������� */
int strcmp(char *s, char *t) 
{	
	while (*s++ == *t++) 
		if (*s == '\0') 
			return 0;
	return *s - *t;
} 

/* strlen�����������ַ���s�ĳ��� */
int strlen(char *s)
{
	char *p = s;
	
	while (*p != '\0') 
		p++;
	return p - s;
} 

/* getline��������һ�ж��뵽s�в������䳤�� */
int getline(char s[], int lim) 
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
		s[i] = c;
/*	if (c == '\n')
		s[i++] = c;*/ 
	s[i] = '\0';
	return i;
}

