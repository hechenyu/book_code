#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;		/* �¶ȱ������ */ 
	upper = 300; 	/* �¶ȱ������ */ 
	step = 20; 		/* ���� */
	
	printf("\tCelsius fahr\n");
	printf("-------------------------\n");
	
	celsius = lower;
	while (celsius <= upper)
	{
		fahr = celsius * 9.0 / 5.0 + 32.0;
		printf("\t%3.0f\t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	
	system("PAUSE");	
	return 0;
}
