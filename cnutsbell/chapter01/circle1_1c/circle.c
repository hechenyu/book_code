/* circle.c:  ��������Բ����� */

#include <stdio.h>			/* Ԥ����ָ�� */

double circularArea(double r);		/* �������� */


int main()				/* main()����Ŀ�ʼ */
{
	double radius = 1.0, area = 0.0;

	printf("	Areas of Circles\n\n");
	printf("	Radius				Area\n"
		   "----------------------------------------------\n");

	area = circularArea(radius);
	printf("  %10.1f			  %10.2f\n", radius, area);

	radius = 5.0;
	area = circularArea(radius);
	printf("  %10.1f			  %10.2f\n", radius, area);

	putchar('\n');
	return 0;
}

/* circularArea()��������Բ�����
 * ����:	Բ�ΰ뾶
 * ����ֵ:	Բ����� */
double circularArea(double r)			/* circularArea()����Ŀ�ʼ */
{
	const double pi = 3.1415926536;		/* pi��һ������ */
	return pi * pow(r, 2.0);
}