/* Getint.c */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);
int getint(int *pn);

int main(int argc, char *argv[])
{
	int test, c;
	
	printf("Enter a number: ");
	getint(&test);
	printf("test = [%d]\n", test);
	
	c = getch();
	printf("c = [%c]", c);
	printf("\n");
	
	system("PAUSE");
	return 0;
}	

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

/* getint: get next integer from input into *pn */
int getint(int *pn) 
{
	int c, d, sign;
	
	while (isspace(c = getch())) 	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') 
	{
		ungetch(c);		/* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') 
	{
		d = c;			/* remember sign char */
		if (!isdigit(c = getch()))
		{
			if (c != EOF)
				ungetch(c);		/* push back non-digit */
			ungetch(d);			/* push back sign char */
			return d;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
} 
 
