#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000	/* ����������е���󳤶� */

int getline(char line[], int maxline);
void copy(char to[], char from[]); 

int main(int argc, char *argv[])
{
	int len;		/* ��ǰ�г��� */
	int max;		/* ĿǰΪֹ���ֵ���еĳ��� */
	char line[MAXLINE];		/* ��ǰ�������� */
	char longest[MAXLINE];	/* ���ڱ�������� */
	
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
	{
		printf("%d, %s", len, line);
		if (len > max)	
		{
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)	/* ������������ */ 
		printf("%s", longest); 
		
	system("PAUSE");	
	return 0;
}

/* getline��������һ�ж��뵽s�в������䳤�� */
#ifdef GETLINE_ONE
int getline(char s[], int lim) 
{
	int c, i, j;
	
	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) 
		if (i < lim - 2)
		{
			s[j] = c;	/* line still in boundaries */
			++j;
		}
	if (c == '\n')
	{
		s[j] = c;
		++j;
		++i;
	}
	s[i] = '\0';
	return i;
}
#else
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
#endif

/* copy��������from���Ƶ�to������ٶ�to�㹻�� */
void copy(char to[], char from[]) 
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0') 
		++i; 
}
