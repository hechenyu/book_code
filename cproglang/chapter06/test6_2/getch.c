/* getch.c */

#include <stdio.h>

#define BUFSIZE		100

char buf[BUFSIZE];		/* ����ungetch�����Ļ����� */
int bufp = 0;			/* buf����һ������λ�� */

int getch(void)			/* ȡһ���ַ�(������ѹ�ص��ַ�) */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 	/* ���ַ�ѹ�ص������� */
{
	if (bufp >= BUFSIZE) 
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
 
