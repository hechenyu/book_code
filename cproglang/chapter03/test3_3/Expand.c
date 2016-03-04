/* Expand.c ����expand(s1, s2)���ַ���s1��������a-zһ����ټǷ������ַ���s2��
			�ȼ۵������б�abc...xyz���ú������Դ����Сд��ĸ�����֣�������
			����a-b-c��a-z0-9��a-z�����Ƶ������ */
			 
#include <stdio.h>

void expand(char shorthand[], char expanded[]);
int getline(char line[], int maxline); 
 
int main(int argc, char *argv[])
{
	const int MAXLEN = 500;
	char shortnote[MAXLEN];
	char expandnote[MAXLEN];
	
	printf("Enter the shorthand notation line:\n");
	getline(shortnote, MAXLEN);
	printf("\nThe shorthand notation line is:\n%s\n", shortnote);
	expand(shortnote, expandnote);
	printf("The expanded notation line is:\n%s\n", expandnote);
	
	system("PAUSE");	
	return 0;
}

/* expand: expand shorthand notation in s1 into strin s2 */
void expand(char s1[], char s2[])
{
	char c;
	int i, j;
	
	i = j = 0;
	while ((c = s1[i++]) != '\0') 	/* fetch a char from s1[] */
		if (s1[i] == '-' && s1[i+1] >= c)
		{
			i++;
			while (c < s1[i])		/* expand shorthand */
				s2[j++] = c++;
		}
		else
			s2[j++] = c;
	s2[j] = '\0';
} 

int getline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') 
		s[i++] = c;
	s[i] = '\0';
} 
