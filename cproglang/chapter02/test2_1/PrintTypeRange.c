/* PrintTypeRange.c ȷ���ֱ���signed��unsigned�޶���char��short��int��long����
					������ȡֵ��Χ�����ô�ӡ��׼ͷ�ļ��е���Ӧֵ�Լ�ֱ�Ӽ���
					���ַ�ʽʵ�� */
					 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printTypeRange1(void);
void printTypeRange2(void);

/* determine ranges of types */
int main(int argc, char *argv[])
{
	printf("Determine ranges of types by limits.h\n");
	printTypeRange1();
	printf("Determine ranges of types by calculate\n");
	printTypeRange2();
	 
	system("PAUSE");	
	return 0;
}

/* ȷ�������ͱ�����ȡֵ��Χ��ͨ�����ô�ӡ��׼ͷ�ļ��е���Ӧֵ */ 
void printTypeRange1(void)
{
	/* signed types */
	printf("signed char min  = %d\n", SCHAR_MIN);
	printf("signed char max  = %d\n", SCHAR_MAX);
	printf("signed short min = %d\n", SHRT_MIN);
	printf("signed short max = %d\n", SHRT_MAX);
	printf("signed int min   = %d\n", INT_MIN);
	printf("signed int max   = %d\n", INT_MAX);
	printf("signed long min  = %ld\n", LONG_MIN);
	printf("signed long max  = %ld\n", LONG_MAX);
	/* unsigned types */
	printf("unsigned char max  = %u\n", UCHAR_MAX);
	printf("unsigned short max = %u\n", USHRT_MAX);
	printf("unsigned int max   = %u\n", UINT_MAX);
	printf("unsigned long max  = %lu\n", ULONG_MAX);
}

/* ȷ�������ͱ�����ȡֵ��Χ��ͨ��������ȷ����Ӧֵ */ 
void printTypeRange2(void)
{
	 /* signed types */
	printf("signed char min  = %d\n", 
			(char)(((unsigned char)~0 >> 1) + 1));
	printf("signed char max  = %d\n", 
			(char)((unsigned char)~0 >> 1));
	printf("signed short min = %d\n", 
			(short)(((unsigned short)~0 >> 1) + 1));
	printf("signed short max = %d\n", 
			(short)((unsigned short)~0 >> 1));
	printf("signed int min   = %d\n", 
			(int)(((unsigned int)~0 >> 1) + 1));
	printf("signed int max   = %d\n", 
			(int)((unsigned int)~0 >> 1));
	printf("signed long min  = %ld\n", 
			(long)(((unsigned long)~0 >> 1) + 1));
	printf("signed long max  = %ld\n", 
			(long)((unsigned long)~0 >> 1));
	/* unsigned types */
	printf("unsigned char max  = %u\n", (unsigned char)~0);
	printf("unsigned short max = %u\n", (unsigned short)~0);
	printf("unsigned int max   = %u\n", (unsigned int)~0);
	printf("unsigned long max  = %lu\n", (unsigned long)~0);
}
