/* main.c */

#include <stdio.h>
#include <ctype.h>

int main()		/* lower������������ת��ΪСд��ʽ */
{
	int c;
	
	while ((c = getchar()) != EOF)
		putchar(tolower(c));
	return 0;
}
