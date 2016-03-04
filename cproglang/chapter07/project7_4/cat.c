/* cat.c */

#include <stdio.h>

/* cat���������Ӷ���ļ����汾1 */
int main(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);
	
	if (argc == 1)		/* ���û�������в��������Ʊ�׼���� */
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL) {
				printf("cat: can't open %s\n", *argv);
				return 1;
			} else {
				filecopy(fp, stdout);
				fclose(fp);
			}
	return 0;
}

/* filecopy���������ļ�ifp���Ƶ��ļ�ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
	int c;
	
	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}
