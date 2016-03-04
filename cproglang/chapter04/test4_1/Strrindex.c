/* Strrindex.c ����strrindex(s, t)�����ַ���t��s�����ұ߳��ֵ�λ�ã����s��
			   ������t���򷵻�-1 */
 
#include <stdio.h>
#include <string.h> 

#define		MAXLINE		1000	/* ��������г��� */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";		/* �����ҵ�ģʽ */ 
 
/* �ҳ�������ģʽƥ����� */ 
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;
	
	while (getline(line, MAXLINE) > 0) 
		if (strrindex(line, pattern) >= 0) 
		{
			printf("%s", line);
			found++;
		}
	 
	system("PAUSE");	
	return found;
}

/* getline���������б��浽s�У������ظ��еĳ��� */
int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n') 
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strindex����������t��s�е�λ�ã���δ�ҵ��򷵻�-1 */
int strrindex(char s[], char t[]) 
{
#if defined STRRINDEX_ONE 
	int i, j, k, pos;
	
	pos = -1; 
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			pos = i;
	} 
	return pos;
#else
	int i, j, k;
	
	for (i = strlen(s) - strlen(t); i >= 0; i--)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
#endif 
}
