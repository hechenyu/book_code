/* Dcl.c */

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

/* dcl��������һ�������������﷨���� */
void dcl(void)
{
	int ns;
	
	for (ns = 0; gettoken() == '*'; )	/* ͳ���ַ�*�ĸ��� */
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

/* dirdcl����������һ��ֱ������ */
void dirdcl(void)
{
	int type;
	
	if (tokentype == '(') {		/* ��ʽΪ(dcl) */ 
		dcl();
		if (tokentype != ')') 
			printf("error: missing )\n");
	} else if (tokentype == NAME) 	/* ������ */
		strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");
	while ((type = gettoken()) == PARENS || type == BRACKETS) 
		if (type == PARENS) 
			strcat(out, " function returing");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
} 

int gettoken(void)		/* ������һ����� */
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;
	
	while ((c = getch()) == ' ' || c == '\t') 
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; ) 
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); ) 
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
} 
