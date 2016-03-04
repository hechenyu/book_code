/* Getline.c ��ӡ���ȴ���80���ַ������������� */
 
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE		1000	/* maximum input line size */
#define LONGLINE	80

int getline(char line[], int maxline);

int main(int argc, char *argv[])
{
	int len;		/* ��ǰ�г��� */
	char line[MAXLINE];		/* ��ǰ�������� */
	
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > LONGLINE)
			printf("%s", line);

	system("PAUSE");	
	return 0;
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
