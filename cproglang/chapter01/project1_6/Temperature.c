#include <stdio.h>
#include <stdlib.h>

#define LOWER	0		/* ������� */
#define UPPER	300 	/* ������� */
#define STEP	20		/* ���� */
 
int main(int argc, char *argv[])
{
 	int fahr;
	
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("\t%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
		
	system("PAUSE");	
	return 0;
}
