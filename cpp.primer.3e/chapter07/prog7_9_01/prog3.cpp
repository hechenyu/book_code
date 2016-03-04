
#include <iostream>
#include <string>

using namespace std;

// typedef ʹ quit_sort() ���������׶�
typedef int ( *PFI2S )( const int &, const int & );

// ��Щͨ��Ӧ����ͷ�ļ���
int lexicoCompare( const int &, const int & );

inline void int_swap(int &a, int &b) 
{
	int c;
	c = a;
	a = b;
	b = c;
}

void quit_sort( int *s1, int *s2, PFI2S compare = lexicoCompare )
{
	// �ݹ��ֹͣ����
	if ( s1 < s2 ) {
		int elem = *s1;
		int *low = s1;
		int *high = s2 + 1;
		for (;;) {
			while ( compare( *++low, elem ) < 0 && low < s2) ;
			while ( compare( elem, *--high ) < 0 && high > s1) ;
			if ( low < high ) {
				int_swap(*low, *high);
			}
			else break;
		} // end, for(;;)
		int_swap(*s1, *high);
		quit_sort( s1, high - 1, compare );
		quit_sort( high + 1, s2, compare );
	} // end, if ( s1 < s2 )
}

int lexicoCompare( const int &s1, const int &s2 ) {
	if (s1 < s2)
		return -1;
	else if (s1 == s2)
		return 0;
	else
		return 1;
}

int as[] = { 1, 4, 3, 7, 4, 2, 6, 8, 5, 9, };

int main() {
	// ���� quit_sort(), ʹ��ȱʡʵ�����Ƚϲ���
	quit_sort( as, as + sizeof(as)/sizeof(as[0]) - 1 );
	// ��ʾ����֮�������Ľ��
	cout << "\t";
	for ( int i = 0; i < sizeof(as)/sizeof(as[0]); ++i )
		cout << as[ i ] << "\n\t";
}
