/* prog2.cpp */
/* on page 130 of C++ Primer 3e */

#include <iostream>
#include <complex>

// �Ѹ��ϲ������Ķ����������
int main()
{
	using std::cout;
	using std::endl;
	using std::complex;
	
	complex< double > cval( 4.0, 1.0 );
	cout << cval << endl;
	cval += 1;
	cout << cval << endl;
	cval -= 1;
	cout << cval << endl;
	cval *= 2;
	cout << cval << endl;
	cval /= 2;
	cout << cval << endl;
}
