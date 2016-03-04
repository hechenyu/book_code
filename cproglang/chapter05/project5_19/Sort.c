/* Sort.c */

#include <stdio.h>
#include <string.h>

#define		MAXLINES	5000	/* �������������� */
char *lineptr[MAXLINES];		/* ָ���ı��е�ָ�� */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right,
			int (*comp)(void *, void *));
int numcmp(char *, char *);

/* ��������ı��н������� */			
int main(int argc, char *argv[])
{
	int nlines;		/* ������������� */
	int numeric;	/* ��������ֵ������numeric��ֵΪ1 */
	
	if (argc > 1 && strcmp(argv[1], "-n") == 0) 
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) 
	{
		qsort((void **)lineptr, 0, nlines-1,
				(int (*)(void *, void *))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
	}
}

/* numcmp����������ֵ˳��Ƚ��ַ���s1��s2 */
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

#define MAXLEN	1000	/* ÿ�������ı��е���󳤶� */

int getline(char *, int);
char *alloc(int);

/* readlines��������ȡ������ */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	char *alloc(int n);
	
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0) 
		if (nlines >= maxlines || (p = alloc(len)) == NULL) 
			return -1;
		else
		{
			line[len-1] = '\0';		/* ɾ�����з� */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* getline: read a line into s, return length */
int getline(char *s, int lim)
{
	int c;
	char *t = s;
	
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - t;
}

/* writelines������д����� */
void writelines(char *lineptr[], int nlines) 
{
	int i;
	
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

#define ALLOCSIZE	8192	/* ���ÿռ��С */

static char allocbuf[ALLOCSIZE];	/* allocʹ�õĴ洢�� */

static char *allocp = allocbuf;		/* ��һ������λ�� */
 
char *alloc(int n)		/* ����ֵָ��n���ַ���ָ�� */ 
{
	if (allocbuf + ALLOCSIZE - allocp >= n) 	/* ���㹻�Ŀ��пռ� */ 
	{
		allocp += n;
		return allocp - n;		/* ����ǰ��ָ��p */
	}
	else
		return 0;
}
