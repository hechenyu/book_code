/* Strindex.c ����strindex(s, t)�����ַ���t��s������߳��ֵ�λ�ã����s��
			  ������t���򷵻�-1 */
 
#include <stdio.h>

#define		MAXLINE		1000	/* ��������г��� */

int getline(char *line, int lim);
int strindex(char *source, char *searchfor);

char pattern[] = "ould";		/* �����ҵ�ģʽ */ 
 
/* �ҳ�������ģʽƥ����� */ 
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;
	
	while (getline(line, MAXLINE) > 0) 
		if (strindex(line, pattern) >= 0) 
		{
			printf("%s", line);
			found++;
		}
	 
	system("PAUSE");	
	return found;
}

/* strindex����������t��s�е�λ��(�����±�)����δ�ҵ��򷵻�-1 */
int strindex(char *s, char *t) 
{
	char *b = s;			/* beginning of string s */
	char *p, *r;
	
	for ( ; *s != '\0'; s++)
	{
		for ( p = s, r = t; *r != '\0' && *p == *r; p++, r++)
			;
		if (r > t && *r == '\0') 
			return s - b;
	}
	return -1;
} 

/* getline���������б��浽s�У������ظ��еĳ��� */
int getline(char *s, int lim)
{
	int c;
	char *t = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n') 
		*s++ = c;
	*s = '\0';
	return s - t;
}
