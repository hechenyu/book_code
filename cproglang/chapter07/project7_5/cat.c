/* cat.c */

#include <stdio.h>

/* cat���������Ӷ���ļ����汾2 */
int main(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);
	char *prog = argv[0];		/* ���³����������������� */
	
	if (argc == 1)		/* ���û�������в��������Ʊ�׼���� */
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				exit(1);
			} else {
				filecopy(fp, stdout);
				fclose(fp);
			}
	if (ferror(stdout)) {
		fprintf(stderr, "%s: error writing stdout\n", prog);
		exit(2);
	}
	exit(0);
}

/* filecopy���������ļ�ifp���Ƶ��ļ�ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
	int c;
	
	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}
