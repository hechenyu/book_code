/* main.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>		/* ��д��־ */
#include <sys/types.h>	/* ���Ͷ��� */
#include <sys/stat.h>	/* stat���صĽṹ */
#include "dirent.h"

void fsize(char *);

/* ��ӡ�ļ����� */
int main(int argc, char **argv)
{
	if (argc == 1)		/* Ĭ��Ϊ��ǰĿ¼ */
		fsize(".");
	else
		while (--argc > 0)
			fsize(*++argv);
	return 0;
}
