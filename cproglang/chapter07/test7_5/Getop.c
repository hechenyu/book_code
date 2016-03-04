/* Getop.c */

#include <stdio.h>
#include <ctype.h>
#include "Calc.h"

/* getop��������ȡ��һ�����������ֵ������ */
#ifdef TEST
int getop(char s[])
{
	int i, c, rc;
	static char lastc[] = " ";
	
	sscanf(lastc, "%c", &c);
	lastc[0] = ' ';		/* clear last chararcter */	
	while ((s[0] = c) == ' ' || c == '\t') 
		if (scanf("%c", &c) == EOF)
			c = EOF;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;		/* not a number */
	i = 0;
	if (isdigit(c))		/* collect integer part */
		do {
			rc = scanf("%c", &c);
			if (!isdigit(s[++i] = c))
				break;
		} while (rc != EOF);
	if (c == '.')		/* collect fraction part */
		do {
			rc = scanf("%c", &c);
			if (!isdigit(s[++i] = c))
				break;
		} while (rc != EOF);
	s[i] = '\0';
	if (rc != EOF)
		lastc[0] = c;
	return NUMBER;
}
#endif

int getop(char s[])
{
	int c, rc;
	float f;
	
	while ((rc = scanf("%c", &c)) != EOF)
		if ((s[0] = c) != ' ' && c != '\t')
			break;
	s[1] = '\0';
	if (rc == EOF)
		return EOF;
	else if (!isdigit(c) && c != '.')
		return c;
	ungetc(c, stdin);
	scanf("%f", &f);
	sprintf(s, "%f", f);
	return NUMBER;
}
