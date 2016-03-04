/* Qsort.c �������� */
 
#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
void printArray(int v[], int left, int right);

int main(int argc, char *argv[])
{
	const int NUM = 100;
	int iArray[NUM], i, n;
	
	for (i = 0; i < NUM; i++)
	{
		n = i / 2;
		if (i % 2 == 0) 
			iArray[i] = 2 * n + 2;
		else 
			iArray[i] = 100 - 2 * n - 1;
	}
	printf("The Array initially is:");
	printArray(iArray, 0, NUM - 1);
	qsort(iArray, 0, NUM - 1);
	printf("\nThe Array after sort is:");
	printArray(iArray, 0, NUM - 1);
	printf("\n");
	 
	system("PAUSE");	
	return 0;
}

/* qsort�������Ե���˳���v[left] ...v[right]�������� */
void qsort(int v[], int left, int right) 
{
	int i, last;
	
	if (left >= right) 		/* �����������Ԫ������������ */
		return;				/* ��ִ���κβ��� */
	swap(v, left, (left + right) / 2);		/* �������Ӽ���Ԫ�� */
	last = left;						/* �ƶ���v[0] */ 
	for (i = left + 1; i <= right; i++) 	/* �����Ӽ� */
		if (v[i] < v[left]) 
			swap(v, ++last, i);
	swap(v, left, last);		/* �ָ������Ӽ���Ԫ�� */
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/* swap����������v[i]��v[j]��ֵ */
void swap(int v[], int i, int j) 
{
	int temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
} 

/* printArray��������ӡ�������� */ 
void printArray(int v[], int left, int right)
{
	int i;
	 
	for (i = left; i <= right; i++) 
	{
		if (i % 5 == 0) 
			printf("\n");
		printf("%3i ", v[i]);
	}
	printf("\n");
}
