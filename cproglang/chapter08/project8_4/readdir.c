/* readdir.c */
#include <sys/dir.h>		/* ����Ŀ¼�ṹ */
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "dirent.h"

/* readdir��������˳���ȡĿ¼�� */
Dirent *readdir(DIR *dp)
{
	struct direct dirbuf;	/* ����Ŀ¼�ṹ */
	static Dirent d;		/* ���أ�����ֲ�Ľṹ */
	
	while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf))
			== sizeof(dirbuf)) {
		if (dirbuf.d_ino == 0)	/* Ŀ¼λ��δʹ�� */
			continue;
		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, DIRSIZ);
		d.name[DIRSIZ] = '\0';	/* �����ֹ�� */
		return &d;
	}
	return NULL;
}
