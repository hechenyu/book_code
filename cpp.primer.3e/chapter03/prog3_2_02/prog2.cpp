/* prog2.cpp */
/* on page 65 of C++ Primer 3e */

#include <iostream>

int main()
{
	using namespace std;
	
	// int ���͵Ķ���
	int value = 2;
	int pow = 10;
	
	cout << value << " raised to the power of "
		 << pow << ": \t";
	int res = 1; // ������
	
	// ѭ���������: ��������res
	// ֱ��cnt ����pow
	for ( int cnt=1; cnt <= pow; ++cnt)
		res = res * value;
	cout << res << endl;
}
