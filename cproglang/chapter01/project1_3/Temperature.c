#include <stdio.h>
#include <stdlib.h>

/* ��fahr = 0, 20, ... , 300ʱ���ֱ�
   ��ӡ�����¶��������¶ȶ��ձ� */ 
int main(int argc, char *argv[])
{
	int fahr, celsius;
	int lower, upper, step;
	
	lower = 0;		/* �¶ȱ������ */ 
	upper = 300; 	/* �¶ȱ������ */ 
	step = 20; 		/* ���� */
	
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
	 
	system("PAUSE");	
	return 0;
}
