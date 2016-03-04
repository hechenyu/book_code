/* Any.c ����any(s1, s2)���ַ���s2�е���һ�ַ����ַ���s1�е�һ�γ��ֵ�λ��
		 ��Ϊ������� */
		 
#include <stdio.h>

int getline(char line[], int maxsize, int delim);
int any(char sour[], char sear[]);
 
int main(int argc, char *argv[])
{
	const int LEN = 51;
	char line[LEN];
	char search[LEN]; 
	int pos; 
	
	printf("������һ���ַ���(��%d���ַ�����)\n", LEN - 1);
	getline(line, LEN, '#');
	printf("����������ƥ��ĵ��ַ���: ");
	getline(search, LEN, '#');
	pos = any(line, search);
	printf("��һ��ƥ���ַ���λ��Ϊ: %d\n", pos);	
		
	system("PAUSE");	
	return 0;
}

/* getline��������һ�ж��뵽s�в������䳤�ȣ�limΪs�ĳ��Ȱ���'\0', 
				endΪ������ */
int getline(char s[], int lim, int end)
{
	int i, c;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != end; ++i)
		s[i] = c;
	s[i] = '\0';
	
	return i;
}

/* any: return first location in s1 where any char from s2 occurs */
int any(char s1[], char s2[])
{
	int i, j;
	
	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])		/* match found? */
				return i;			/* location first match */

	return -1; 		/* otherwise, no match */
} 
