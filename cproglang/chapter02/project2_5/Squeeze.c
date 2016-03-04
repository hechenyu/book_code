/* Squeeze.c ����squeeze(s, c)ɾ���ַ���s�г��ֵ������ַ�c */
 
#include <stdio.h>

int getline(char line[], int maxline);
void squeeze(char str[], int c);

int main(int argc, char *argv[])
{
	const int LEN = 51;
	char line[LEN];
	int c;
 	/* int c = 0; */	 /* c�����ȳ�ʼ��Ϊ0����Ȼsqueeze�޷��õ�����Ҫ�Ľ�� */ 
	
	printf("������һ���ַ���(��%d���ַ�����)\n", LEN - 1);
	getline(line, LEN);
	printf("����������ɾ�����ַ�: ");
	/* scanf("%c", &c); */
	c = getchar();
	printf("ԭ�ַ���Ϊ: \n\t%s\n", line);
	printf("����ɾ�����ַ�Ϊ: %c\n", c);
	squeeze(line, c);
	printf("\nɾ������ַ���Ϊ: \n\t%s", line);
	
	system("PAUSE");	
	return 0;
}

/* getline��������һ�ж��뵽s�в������䳤�� ��limΪs�ĳ��Ȱ���'\0' */
int getline(char s[], int lim) 
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
} 

/* squeeze���������ַ�����sɾ���ַ�c */
void squeeze(char s[], int c) 
{
	int i, j;
	
	for (i = j = 0; s[i] != '\0'; i++) 
		if (s[i] != c) 
			s[j++] = s[i];
	
	s[j] = '\0';
} 
	 
