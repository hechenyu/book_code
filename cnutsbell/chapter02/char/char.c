/* char.c:  char���͵ı��� */

#include <stdio.h>


int main()
{
	char ch = 'A';
	printf("The character %c has the character code %d.\n", ch, ch);
	for ( ; ch <= 'Z'; ++ch )
		printf("%2c", ch);

	printf("\n");
	return 0;
}