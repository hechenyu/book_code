#include <stdio.h>
#include <stdlib.h>

/* ͳ��������ַ������汾2 */ 
int main(int argc, char *argv[])
{
	double nc;
	
	for (nc =0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);
	
	system("PAUSE");	
	return 0;
}
