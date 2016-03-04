#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000	/* ����������е���󳤶� */

int max;		/* ĿǰΪֹ���ֵ���еĳ��� */
char line[MAXLINE];		/* ��ǰ�������� */
char longest[MAXLINE];	/* ���ڱ�������� */
	
int getline(void);
void copy(void); 

/* ��ӡ��������У��ر�汾 */ 
int main(int argc, char *argv[])
{
	int len;		/* ��ǰ�г��� */
	extern int max;
	extern char longest[]; 
	
	max = 0;
	while ((len = getline()) > 0)
		if (len > max)	
		{
			max = len;
			copy();
		}
	if (max > 0)	/* ������������ */ 
		printf("%s", longest); 
		
	system("PAUSE");	
	return 0;
}

/* getline�������ر�汾 */
int getline(void) 
{
	int c, i;
	extern char line[]; 
	
	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
		line[i] = c;
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* copy�������ر�汾 */
void copy(void) 
{
	int i;
	extern char line[], longest[];
	 
	i = 0;
	while ((longest[i] = line[i]) != '\0') 
		++i; 
}
