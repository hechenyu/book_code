// ͨ�õ�ģ�嶨��
template <class T>
T max( T t1, T t2 ) {
	return (t1 > t2 ? t1 : t2);
}

#include <cstring>
// const char* ��ʽ�ػ�:
// ����������ͨ��ģ�嶨���ʵ��
typedef const char *PCC;
template<> PCC max< PCC >( PCC s1, PCC s2 ) {
	return ( strcmp( s1, s2 ) > 0 ? s1 : s2 );
}

#include <iostream>
// ����ģ�� max() �Ķ����Լ��� const char* ���ػ�
int main() {
	using std::cout;
	using std::endl;
	
	// ����ʵ��: int max< int >( int, int );
	int i = max( 10, 5 );
	
	// ������ʽ�ػ�: const char* max< const char* >( const char*, const char* );
	const char *p = max( "hello", "world" );
	cout << "i: " << i << " p: " << p << endl;
	
	return 0;
}
