/* _fillbuf.c */
#include <unistd.h>
#include <fcntl.h>

/* _fillbuf���������䲢������뻺���� */
int _fillbuf(FILE *fp)
{
	int bufsize;
	
	if ((fp->flag&(_READ|_EOF|_ERR)) != _READ)
		return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL)		/* ��δ���仺���� */
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF;			/* ���ܷ��仺���� */
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flag |= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}
