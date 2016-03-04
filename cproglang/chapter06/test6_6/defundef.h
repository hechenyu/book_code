/* defundef.h */

#define MAXWORD		100

struct nlist {		/* ������ */
	struct nlist *next;		/* ��������һ�� */
	char *name;				/* ��������� */
	char *defn;				/* �滻�ı� */
};

void error(int, char *);
int getch(void);
void getdef(void);
int getword(char *, int);
struct nlist *install(char *, char *);
struct nlist *lookup(char *);
void skipblanks(void);
void undef(char *);
void ungetch(int);
void ungets(char *);
char *strup(char *);
unsigned hash(char *);
	