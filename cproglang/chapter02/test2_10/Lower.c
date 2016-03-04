/* Lower.c ����lower(c)��ASCII�ַ����е��ַ�ӳ�䵽��Ӧ��Сд��ĸ */
 
#include <stdio.h>

int getline(char line[], int maxline); 
int lower(int c);
int upper(int c); 
 
int main(int argc, char *argv[])
{
	const int LEN = 51;
	char line[LEN];
	int i, c;
	 
	printf("������һ���ַ�(%d���ַ�����)\n", LEN - 1);
	getline(line, LEN);
	printf("��������ַ���Ϊ:\n\t%s", line);
	printf("�ַ�����ȫСд��Ϊ:\n\t");
	for (i = 0; (c = line[i]) != '\0'; ++i) 
		putchar(lower(c));
	printf("�ַ�����ȫ��д��Ϊ:\n\t");
	for (i = 0; (c = line[i]) != '\0'; ++i)
		putchar(upper(c));
		 
	system("PAUSE");	
	return 0;
}

int getline(char s[], int lim)
{
	int i, c;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
 
/* lower���������ַ�cת��ΪСд��ʽ��ֻ��ASCII�ַ�����Ч */
int lower(int c) 
{
	return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
}  

/* upper���������ַ�cת��Ϊ��д��ʽ��ֻ��ASCII�ַ�����Ч */
int upper(int c) 
{
	return c >= 'a' && c <= 'z' ? c - 'a' + 'A' : c;
} 
