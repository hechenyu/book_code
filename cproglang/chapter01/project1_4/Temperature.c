/* ��fahr = 0, 20, ... , 300ʱ���ֱ�
   ��ӡ�����¶��������¶ȶ��ձ� */ 
int main(int argc, char *argv[])
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;		/* �¶ȱ������ */ 
	upper = 300; 	/* �¶ȱ������ */ 
	step = 20; 		/* ���� */
	
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5.0 * (fahr - 32.0) / 9.0;
		printf("%3.0f%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	 
	system("PAUSE");	
	return 0;
}
