/* Strcmp.c */
 
#include <stdio.h>

#define LEN		128
 
int strcmp(char *str1, char *str2);
int getline(char line[], int maxline);

int main(int argc, char *argv[])
{
	char response;
	char str1[LEN], str2[LEN];
	int result; 
	
	do
	{ 
		printf("�����һ���ַ���(С��128���ַ�), �Իس�����\n");
		getline(str1, LEN);
		printf ("����ڶ����ַ���(С��128���ַ�), �Իس�����\n");
		getline(str2, LEN);
		
		result = strcmp(str1, str2);
		if (result == 0)
			printf("��һ���ַ������ڵڶ����ַ���.\n");
		else if (result > 0)
			printf("��һ���ַ������ڵڶ����ַ���.\n");
		else
			printf("��һ���ַ���С�ڵڶ����ַ���.\n"); 
		
		printf("������? (y/n): ");
		result = getchar();
		while(getchar() != '\n')
			; 
	} 
	while (result != 'n' && result != 'N');
	
	system("PAUSE");	
	return 0;
}

/* strcmp����������s�����ֵ�˳��С�ڡ����ڻ����t�Ľ���ֱ𷵻ظ�������0
			   �������� */
int strcmp(char *s, char *t) 
{
	int i;
	
	for (i = 0; s[i] == t[i]; i++) 
		if (s[i] == '\0') 
			return 0;
	return s[i] - t[i];
} 

/* getline��������һ�ж��뵽s�в������䳤�� */
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
