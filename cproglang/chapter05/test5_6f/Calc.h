/* Calc.h */

#ifndef CALC_H
#define CALC_H
 
#define NUMBER '0'		/* ��ʶ�ҵ�һ���� */

int getop(char *);
void push(double);
double pop(void); 
int getch(void);
void ungetch(int); 

#endif 
