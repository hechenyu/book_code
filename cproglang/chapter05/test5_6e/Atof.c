/* Atof.c ���ַ���ת��Ϊ˫���ȸ����� */
 
#include <stdio.h>
#include <ctype.h> 

#define MAXLINE 100

int getline(char *line, int lim);  
double atof(char *str);

/* �򵥼��������� */ 
int main(int argc, char *argv[])
{
	double sum, tmp;
	char line[MAXLINE]; 
	
	sum = 0.0; 
	while (getline(line, MAXLINE) > 0)
	{
		printf("line = [%s]\n", line);
		tmp = atof(line);
		printf("tmp = [%7.2lf]\n", tmp); 
		sum += atof(line); 
		printf("\t%lf\n", sum);
	}
		
	system("PAUSE");	
	return 0;
}

/* atof���������ַ���sת��Ϊ��Ӧ��˫���ȸ����� */
double atof(char *s)
{
	double val, power;
	int exp, sign;
	
	for ( ; isspace(*s); s++)		/* �����հ� */
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	for (val = 0.0; isdigit(*s); s++) 
		val = 10.0 * val + (*s - '0');
	if (*s == '.')
		s++;
	for (power = 1.0; isdigit(*s); s++) 
	{
		val = 10.0 * val + (*s - '0');
		power *= 10.0;
	}
	val = sign * val / power;
	
	if (*s == 'e' || *s == 'E') 
	{
		sign = (*(++s) == '-') ? -1 : 1;
		if (*s == '+' || *s == '-')
			s++;
		for (exp = 0; isdigit(*s); s++)
			exp = 10 * exp + (*s - '0');
		if (sign == 1)
			while (exp-- > 0)		/* positive exponent */
				val *= 10;
		else
			while (exp-- > 0)		/* negative exponent */ 
				val /= 10;
	}
	return val; 
} 

/* getline���������б��浽s�У������ظ��еĳ��� */
int getline(char *s, int lim)
{
	int c;
	char *t = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
/*	if (c == '\n') 
		*s++ = c;*/
	*s = '\0';
	return s - t;
}
