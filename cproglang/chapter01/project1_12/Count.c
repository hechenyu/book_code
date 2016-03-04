#include <stdio.h>
#include <stdlib.h>

#define IN	1	/* �ڵ����� */
#define OUT	0	/* �ڵ����� */

/* ͳ����������������������ַ��� */ 
int main(int argc, char *argv[])
{
	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) 
	{
		++nc;
		if (c == '\n') 
			++nl;
		if (c == ' ' || c == '\n' || c == '\t') 
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
  
	system("PAUSE");	
	return 0;
}
