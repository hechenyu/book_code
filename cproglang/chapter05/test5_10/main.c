/* main.c �沨�������� */ 

#include <stdio.h>
#include <stdlib.h>
#include "Calc.h"

#define MAXOP	100		/* �����������������󳤶� */

/* �沨�������� */ 
int main(int argc, char *argv[])
{
	double op2;
	char s[MAXOP];
	
	while (--argc > 0) 
	{
		ungets(" ");		/* push end of argument */
		ungets(*++argv);	/* push an argument */ 
		switch (getop(s))
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0) 
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break; 
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unkown command %s\n", s);
			break;
		}
	}
	 
	system("PAUSE");	
	return 0;
}
