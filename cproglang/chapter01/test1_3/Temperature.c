#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;		/* �¶ȱ������ */ 
	upper = 300; 	/* �¶ȱ������ */ 
	step = 20; 		/* ���� */
	
	printf("\tFahr celsius\n");
	printf("-------------------------\n");
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5.0 * (fahr - 32.0) / 9.0;
		printf("\t%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	
	system("PAUSE");	
	return 0;
}
