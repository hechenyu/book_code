template <class T> T min5( T, T ) { /* ... */ }
unsigned int ui;

int main() {
	// ����: ����ʵ���� min5( unsigned int, int )
	// ������: min( unsigned int, unsigned int ) ��
	// min( int, int )
	min5( ui, 1024 );

	return 0;
}
