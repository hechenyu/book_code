#include <cstring>
#include <cstdlib>

int ival = 1024;
void *pv;
int *pi = &ival;
const char *pc = "a casting call";
void mumble()
{
	pv = pi; // ok: pv ָ�� ival
	pi = pv; // ����: û�б�׼��ת��
	char *pstr = new char[ strlen( pc )+1 ];
	char *pstr2 = malloc(strlen(pc) + 1);	// ����: û�б�׼��ת��
	strcpy( pstr, pc );
}