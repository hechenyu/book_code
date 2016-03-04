/* closedir.c */
#include <unistd.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "dirent.h"

/* closedir�������ر���opendir�򿪵�Ŀ¼ */
void closedir(DIR *dp)
{
	if(dp) {
		close(dp->fd);
		free(dp);
	}
}
