/* Blank.c һ�������븴�Ƶ�����ĳ��򣬲������������Ķ���ո���һ���ո���� */
 
#include <stdio.h>
#include <stdlib.h>

#define STYLE_TWO
#define NONBLANK 'a'
 
int main(int argc, char *argv[])
{
	int c, lastc;
	
	lastc = NONBLANK;
#ifdef STYLE_ONE	/* style if */
	printf("This is the style of \"if\"\n");
	while ((c = getchar()) != EOF) 
	{
		if (c != ' ')
			putchar(c);
		if (c == ' ')
			if (lastc != ' ')
				putchar(c);
		lastc = c;
	}
#elif defined STYLE_TWO	/* style if-else */
	printf("This is the style of \"if-else\"\n");
	while ((c = getchar()) != EOF) 
	{
		if (c != ' ')
			putchar(c); 
		else if (lastc != ' ')
			putchar(c);
		lastc = c;
	}
#else	/* style if( || ) */
	printf("This is the style of \"if( || )\"\n");
	while ((c = getchar()) != EOF) 
	{
		if (c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
#endif
	
	system("PAUSE");	
	return 0;
}
