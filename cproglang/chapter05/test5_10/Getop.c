/* Getop.c */

#include <stdio.h>
#include <ctype.h>
#include "Calc.h"

/* getop��������ȡ��һ�����������ֵ������ */
int getop(char s[])
{
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t') 
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;		/* ������ */
	i = 0;
	if (isdigit(c))		/* �ռ��������� */
		while (isdigit(s[++i] = c = getch())) 
			;
	if (c == '.') 		/* �ռ�С������ */
		while (isdigit(s[++i] = c = getch())) 
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
 
