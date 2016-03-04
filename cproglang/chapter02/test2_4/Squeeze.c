/* Squeeze.c ����squeeze(s1, s2)���ַ���s1���κ����ַ���s2���ַ�ƥ����ַ���
			 ɾ�� */
 
#include <stdio.h>

int getline(char line[], int maxline);
void squeeze(char s1[], char s2[]);

int main(int argc, char *argv[])
{
	const int LEN = 51;
	char line[LEN];
	char str[LEN];		 
	
	printf("������һ���ַ���(��%d���ַ�����)\n", LEN - 1);
	getline(line, LEN);
	printf("����������ɾ�����ַ���(��%d���ַ�����): ", LEN - 1);
	getline(str, LEN);
	printf("ԭ�ַ���Ϊ: \n\t%s\n", line);
	printf("����ɾ�����ַ���Ϊ: %s\n", str);
	squeeze(line, str);
	printf("\nɾ������ַ���Ϊ: \n\t%s\n", line);
	
	system("PAUSE");	
	return 0;
}

/* getline��������һ�ж��뵽s�в������䳤�� ��limΪs�ĳ��Ȱ���'\0' */
int getline(char s[], int lim) 
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
} 

/* squeeze: delete each char in s1 which is in s2 */
void squeeze(char s1[], char s2[]) 
{
	int i, j, k;
	
	for (i = k = 0; s1[i] != '\0'; i++) 
	{
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;
		if (s2[j] == '\0')		/* end of string - no match */
			s1[k++] = s1[i];
	}
	
	s1[k] = '\0';
} 
	 
