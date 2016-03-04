/* Reverse.c ÿ�εߵ�һ���������е��ַ�˳�� */
 
#include <stdio.h>
#include <string.h>

#define MAXLINE		1000	/* maximum input line size */

int getline(char line[], int maxline);
void reverse(char s[]);

/* reverse input lines, a line at a time */
int main(int argc, char *argv[])
{
	char line[MAXLINE];		/* ��ǰ�������� */
	
	while (getline(line, MAXLINE) > 0)
	{
		reverse(line);
		printf("%s", line);
	}
	
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
