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

	return 0;
}

