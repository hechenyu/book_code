/* Console.c */
 
#include <stdio.h>

/* ���Գ��������в������汾2 */ 
int main(int argc, char *argv[])
{
	while (--argc > 0)
		printf("%s%s", *++argv, (argc > 1) ? " " : "");
	printf("\n");
	
	system("PAUSE");	
	return 0;
}
