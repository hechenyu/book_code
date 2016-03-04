/* Daytab.c */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(int argc, char *argv[])
{
	int year, day, month;
	int number;
	
	printf("��������(MM/DD/YYYY): ");
	scanf("%d/%d/%d", &month, &day, &year);
	number = day_of_year(year, month, day);
	if (number == -1)
	{
		printf("�������ڷǷ�");
		exit(1);
	} 
	printf("%d��%d��%d������һ��ĵ�%d��\n", year, month, day, number);
	
	printf("�������: ");
	scanf("%d", &year);
	printf("��������: ");
	scanf("%d", &number);
	month_day(year, number, &month, &day);
	if (month == -1 && day == -1)
	{
		printf("������ݻ������Ƿ�");
		exit(1);
	} 
	printf("%d��ĵ�%d����%d��%d��\n", year, number, month, day);
	 
	system("PAUSE");	
	return 0;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year��������ĳ��ĳ�յ����ڱ�ʾ��ʽת��Ϊĳ���еڼ���ı�ʾ��ʽ */ 
int day_of_year(int year, int month, int day)
{
	int i, leap;
	
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (month < 1 || month > 12)
		return -1;
	if (day < 1 || day > daytab[leap][month])
		return -1;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day��������ĳ���еڼ�������ڱ�ʾ��ʽת��Ϊĳ��ĳ�յı�ʾ��ʽ */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	
	if (year < 1)
	{
		*pmonth = -1;
		*pday = -1;
		return;
	}
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	if (i > 12 && yearday > daytab[leap][12])
	{
		*pmonth = -1;
		*pday = -1;
	}
	else
	{
		*pmonth = i;
		*pday = yearday;
	}
} 
