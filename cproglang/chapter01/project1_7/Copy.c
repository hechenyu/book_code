#include <stdio.h>
#include <stdlib.h>

/* �����븴�Ƶ�������汾1 */ 
int main(int argc, char *argv[])
{
	int c;
	
	c = getchar();
	while (c != EOF)
	{
		putchar(c);
		c = getchar();
	}
	 
	system("PAUSE");	
	return 0;
}
