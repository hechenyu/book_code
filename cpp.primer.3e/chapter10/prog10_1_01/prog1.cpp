// ����ģ�� min() �Ķ���
// ��һ�����Ͳ��� Type ��һ�������Ͳ��� size
template <typename Type, int size>
Type min( Type (&r_array)[size] )
{
	Type min_val = r_array[0];
	for ( int i = 1; i < size; ++i )
		if ( r_array[i] < min_val )
			min_val = r_array[i];
	
	return min_val;
}

// size û��ָ������ok
// size = ��ʼ�����е�ֵ�ĸ���
int ia[] = { 10, 7, 14, 3, 25 };

double da[6] = { 10.2, 7.1, 14.5, 3.2, 25.0, 16.8 };

#include <iostream>
int main()
{
	using std::cout;
	// Ϊ5 ��int ������ʵ����min()
	// Type => int, size => 5
	int i = min( ia );
	if ( i != 3 )
		cout << "??oops: integer min() failed\n";
	else cout << "!!ok: integer min() worked\n";
	
	// Ϊ 6 �� double ������ʵ���� min()
	// Type => double, size => 6
	double d = min( da );
	if ( d != 3.2 )
		cout << "??oops: double min() failed\n";
	else cout << "!!ok: double min() worked\n";
	
	return 0;
}
