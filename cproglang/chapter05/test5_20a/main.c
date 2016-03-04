/* main.c */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define		MAXTOKEN	100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype;				/* ���һ���Ǻŵ����� */
char token[MAXTOKEN]; 		/* ���һ���Ǻ��ַ��� */
char name[MAXTOKEN];		/* ��ʾ���� */
char datatype[MAXTOKEN];	/* ��������Ϊchar��int�� */
char out[1000];				/* ����� */ 

int main(int argc, char *argv[])	/* ������ת��Ϊ�������� */ 
{
	while (gettoken() != EOF) {		/* ���еĵ�һ���Ǻ����������� */
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();		/* �������е����ಿ�� */ 
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s:%s %s\n", name, out, datatype);
	}
	system("PAUSE");	
	return 0;
}

