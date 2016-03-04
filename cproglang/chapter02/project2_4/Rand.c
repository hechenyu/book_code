/* Rand.c �漴���������� */ 

#include <stdio.h>
#include <time.h> 

unsigned long int next = 1;		/* ���� */
 
int rand(void);
void srand(unsigned int seed); 

int main(int argc, char *argv[])
{
	int i; 
	int num; 
	unsigned int tm; 
	
	printf("����rand()10��(����Ϊ1)\n");
	for (i = 1; i <= 10; ++i)
	{
		num = rand();
		printf("%d ", num);
	}
	
	tm = (unsigned)time(0);		/* ȡ��ǰ���� */ 
	srand(tm);					/* �������� */ 
	printf("\n����rand()10��(����Ϊ%u)\n", tm);
	for (i = 1; i <= 10; ++i)
	{
		num = rand();
		printf("%d ", num);
	}
	
	system("PAUSE");	
	return 0;
}

/* rand����������ȡֵ��0~32767֮���α����� */ 
int rand(void) 
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

/* srand������Ϊrand()�������������� */
void srand(unsigned int seed)
{
	next = seed;
} 
