/* Calc.h */

#ifndef CALC_H
#define CALC_H
 
#define NUMBER '0'		/* 标识找到一个数 */

int getop(char []);
void push(double);
double pop(void); 
int getch(void);
void ungetch(int);
void ungets(char *);

#endif 
