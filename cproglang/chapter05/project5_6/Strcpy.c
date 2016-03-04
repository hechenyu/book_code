/* Strcpy.c */
 
#include <stdio.h>
#include <stdlib.h> 

int strlen(char *s);
void strcpy(char *destination, char *source);

int main(int argc, char *argv[])
{
	char s[] = "Hello, I am hexu!";
	char *p;
	int len; 
	
	len = strlen(s) + 1; 
	p = malloc(len);
	strcpy(p, s);
	printf("s = [%s]\np = [%s]\n", s, p);
	
	system("PAUSE");	
	return 0;
}

/* strcpy��������ָ��tָ����ַ������Ƶ�ָ��sָ���λ�ã�
			   ʹ��ָ�뷽ʽʵ�ֵİ汾1 */
void strcpy(char *s, char *t) 
{
	while ((*s = *t) != '\0') 
	{
		s++;
		t++;
	} 
}
 
/* strlen�����������ַ���s�ĳ��� */
int strlen(char *s)
{
	char *p = s;
	
	while (*p != '\0') 
		p++;
	return p - s;
} 
