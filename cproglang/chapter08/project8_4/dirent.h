/* dirent.h */
#define	NAME_MAX	14	/* ��ļ������ɾ����ϵͳ���� */

typedef struct {	/* ����ֲ��Ŀ¼�� */
	long ino;		/* i�ڵ��� */
	char name[NAME_MAX+1];	/* �ļ����ӽ�����'\0' */
} Dirent;

typedef struct {	/* ��С��DIR: �޻�������� */
	int fd;			/* Ŀ¼���ļ������� */
	Dirent d;		/* Ŀ¼�� */
} DIR;

