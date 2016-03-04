/* Strcat.c ����strcat(s, t)���ַ���t���ӵ��ַ���s��β�� */
 
#include <stdio.h>

void getline(char line[], int maxlen); 
void strcat(char dest[], char sour[]);
 
int main(int argc, char *argv[])
{
	const int LEN1 = 51, LEN2 = 26;
	char str1[LEN1], str2[LEN2];
	printf("�������һ���ַ�(25���ַ�����):\n");
	getline(str1, LEN2);
	printf("������ڶ����ַ�(25���ַ�����):\n"); 
	getline(str2, LEN2);
	printf("�������һ���ַ�Ϊ:\nstr1 = [%s]", str1);
	printf("������ڶ����ַ�Ϊ:\nstr2 = [%s]", str2);
	printf("���潫str2���ӵ�str1��\n");
	strcat(str1, str2);
	printf("���Ӻ��str1Ϊ:\nstr1 = [%s]", str1);
	
	system("PAUSE");	
	return 0;
}

/* getline��������һ�ж��뵽s�в������䳤�� ��limΪs�ĳ��Ȱ���'\0' */
void getline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') 
		s[i++] = c;
	s[i] = '\0';
	
	return i;
} 

/* strcat���������ַ���t���ӵ��ַ���s��β����s�������㹻��Ŀռ� */ 
void strcat(char s[], char t[])
{
	int i, j;
	
	i = j = 0;
	while (s[i] != '\0')	/* �ж��Ƿ�Ϊ�ַ���s��β�� */
		i++;
	while ((s[i++] = t[j++]) != '\0') 	/* ����t */
		;
} 
