/* dirwalk.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>		/* ��д��־ */
#include <sys/types.h>	/* ���Ͷ��� */
#include <sys/stat.h>	/* stat���صĽṹ */
#include "dirent.h"
#define MAX_PATH	1024

/* dirwalk��������dir�е������ļ����ú���fcn */
void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	Dirent *dp;
	DIR *dfd;
	
	if((dfd = opendir(dir)) == NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}
	while ((dp = readdir(dfd)) != NULL) {
		if (strcmp(dp->name, ".") == 0 || 
			strcmp(dp->name, "..") == 0)
			continue;		/* ��������͸�Ŀ¼ */
		if (strlen(dir)+strlen(dp->name)+2 > sizeof(name))
			fprintf(stderr, "dirwalk: name %s/%s too long \n",
					dir, dp->name);
		else {
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
}
