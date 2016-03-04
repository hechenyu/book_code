/* Reverse.c ÿ�εߵ�һ���������е��ַ�˳�� */
 
#include <stdio.h>
#include <string.h>

#define MAXLINE		1000	/* maximum input line size */

int getline(char line[], int maxline);
void reverse(char s[]);
void reverser(char s[], int i, int len);

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

/* reverse: reverse string s in place */
void reverse(char s[])
{
	reverser(s, 0, strlen(s));
}

/* reverse: reverse sring s in place; recursive*/
void reverser(char s[], int i, int len)
{
	int c, j;
	
	j = len - (i + 1);
	if (i < j )
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		reverser(s, ++i, len);
	}
}
