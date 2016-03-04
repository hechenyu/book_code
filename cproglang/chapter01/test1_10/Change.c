/* Change.c һ�������븴�Ƶ�����ĳ��򣬲������е��Ʊ���滻Ϊ\t���ѻ��˷�
			�滻Ϊ\b���ѷ�б���滻Ϊ\\ */
						 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int c;

#ifdef STYLE_ONE	
	while ((c = getchar())!= EOF)
	{
		if (c == '\t')
			printf("\\t");
		if (c == '\b')
			printf("\\b");
		if (c == '\\')
			printf("\\\\");
		if (c != '\b')
			if (c != '\t')
				if (c != '\\')
					putchar(c);
	}
#else
	while ((c = getchar()) != EOF)
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
#endif

	system("PAUSE");	
	return 0;
}
