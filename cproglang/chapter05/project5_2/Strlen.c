/* Strlen.c strlen(s)�������Է����ַ�������s�ĳ��ȣ������Ȳ�����
			ĩβ��'\0' */
			
#include <stdio.h>

int strlen(char *str);
int getline(char line[], int maxline);

int main(int argc, char *argv[])
{
	const int LEN = 21;
	char str[LEN];
	int len; 
	 
	printf("����һ���ַ�����20���ַ����ڣ�\n");
	getline(str, LEN); 
	len = strlen(str);
	printf("\n%s�ĳ���Ϊ%d\n", str, len);
	
	system("PAUSE");	
	return 0;
}

/* strlen����������s�ĳ��� */ 
int strlen(char *s)
{
	int n;
	
	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}

/* getline��������һ�ж��뵽s�в������䳤�� */
int getline(char s[], int lim) 
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
