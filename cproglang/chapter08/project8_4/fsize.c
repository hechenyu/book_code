/* fsize.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>		/* ��д��־ */
#include <sys/types.h>	/* ���Ͷ��� */
#include <sys/stat.h>	/* stat���صĽṹ */
#include "dirent.h"

void dirwalk(char *, void (*fcn)(char *));

/* fsize��������ӡ�ļ�name�ĳ��� */
void fsize(char *name)
{
	struct stat stbuf;
	
	if (stat(name, &stbuf) == -1) {
		fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}
	if ((stbuf.st_mode & S_IFDIR))
		dirwalk(name, fsize);
	printf("%8ld %s\n", stbuf.st_size, name);
}
