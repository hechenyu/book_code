#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(int argc, char *argv[])
{
	const int LEN = 100; 
	int iArray[LEN];
	int iSearch, i, iPos; 
	
	for (i = 1; i <= 100; ++i)
		iArray[i] = i * 10;
	
	printf("������Ҫ���ҵ���: ");
	scanf("%d", &iSearch);
	iPos = binsearch(iSearch, iArray, LEN);
	if (iPos == -1)
		printf("Sorry, û������Ҫ��.\n");
	else
		printf("Oh, �ڵ�%d��λ���ҵ�%d.\n", iPos, iSearch);		 
	
	system("PAUSE");	
	return 0;
}

/* binsearch��������v[0]<=v[1]<=v[2]<=...<=v[n-1]�в���x */ 
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* �ҵ���ƥ���ֵ */
			return mid;
	} 
	return -1;	/* û��ƥ���ֵ */
} 
