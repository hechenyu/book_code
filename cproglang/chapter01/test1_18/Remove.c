/* Remove.c ɾ��ÿ��������ĩβ�Ŀո��Ʊ������ɾ����ȫ�ǿո���� */
 
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE		1000	/* maximum input line size */

int getline(char line[], int maxline);
int Remove(char s[]);

int main(int argc, char *argv[])
{
	char line[MAXLINE];		/* ��ǰ�������� */
	
	while (getline(line, MAXLINE) > 0)
		if (Remove(line) > 0)
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

/* Remove trailing blanks and tabs from character string s */
int Remove(char s[])
{
	int i;
	
	i = 0;
	while (s[i] != '\n')	/* find newline character */
		++i;
	--i;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	if (i >= 0)				/* is it a nonblank line? */
	{
		++i;
		s[i] = '\n';		/* put newline character back */
		++i;
		s[i] = '\0';
	}
	return i;
}

