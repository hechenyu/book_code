/* Alloc.c ��̬�����ڴ�ռ� */
 
#include <stdio.h>

char *alloc(int n);
void afree(char *p);
void showbuf(int beg, int end);
void showstr(char *p, int n);

int main(int argc, char *argv[])
{
	int i, a1, a2, n;
	char *str1, *str2, *str3;
	
	n = 12;
	str1 = alloc(n);
	for (i = 0; i < n; i++) 
		*(str1 + i) = 'a' + i;
	printf("\nstr1 =\n");
	showstr(str1, n);
	
	n = 14;
	str2 = alloc(n); 
	for (i = 0; i < n; i++) 
		*(str2 + i) = 'A' + i;	
	printf("\nstr2 =\n");
	showstr(str2, n);
	
	a1 = 0;
	a2 = 26; 
	printf("\nallocbuf from %d to %d is:\n", a1, a2 - 1);
	showbuf(a1, a2); 
	
	afree(str2);
	n = 6;
	str3 = alloc(n);
	for (i = 0; i < n; i++)
		*(str3 + i) = '0' + i;
	printf("\nstr3 =\n");
	showstr(str3, n);		
	 
	a1 = 0;
	a2 = 26; 
	printf("\nallocbuf from %d to %d is:\n", a1, a2 - 1);
	showbuf(a1, a2);
	
	printf("\n");
	system("PAUSE");	
	return 0;
}

#define ALLOCSIZE	8192	/* ���ÿռ��С */

static char allocbuf[ALLOCSIZE];	/* allocʹ�õĴ洢�� */

static char *allocp = allocbuf;		/* ��һ������λ�� */

char *alloc(int n)		/* ����ֵָ��n���ַ���ָ�� */ 
{
	if (allocbuf + ALLOCSIZE - allocp >= n) 	/* ���㹻�Ŀ��пռ� */ 
	{
		allocp += n;
		return allocp - n;		/* ����ǰ��ָ��p */
	}
	else
		return 0;
}

void afree(char *p) 	/* �ͷ�pָ��Ĵ洢�� */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) 
		allocp = p;
}

void showbuf(int beg, int end) 	/* �����������[beg,end)�е������ַ�����ʼλ��Ϊ0 */ 
{
	char *ptmp;
	int len, i;
	 
	for (ptmp = allocbuf + beg, i = 0, len = end - beg; i < len; i++)
		printf("%c", *(ptmp + i));
}

void showstr(char *p, int n) /* ����ַ�����ָ���ַ���ʼ��n���ַ� */
{
	int i;
	
	for (i = 0; i < n; i++)
		printf("%c", *(p + i));
}

 
