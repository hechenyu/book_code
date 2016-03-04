/* Stack.c */

#include <stdio.h>
#include "Calc.h"

#define MAXVAL	100		/* ջval�������� */

int sp = 0;				/* ��һ������ջ��λ�� */ 
double val[MAXVAL]; 	/* ֵջ */

/* push��������fѹ�뵽ֵջ�� */
void push(double f)
{
	if (sp < MAXVAL) 
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop����������������ջ����ֵ */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* clear: clear the stack */
void clear(void)
{
	sp = 0;
}
 
 
