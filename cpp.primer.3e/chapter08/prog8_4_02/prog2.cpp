#include <iostream>

using std::cout;
using std::endl;

const int iterations = 2;

void func() {
	int value1, value2; // δ��ʼ��
	static int depth; // ��ʽ��ʼ��Ϊ0
	if ( depth < iterations )
	{ ++depth; func(); }
	else depth = 0;
	cout << "\nvalue1:\t" << value1;
	cout << "\tvalue2:\t" << value2;
	cout << "\tsum:\t" << value1 + value2;
}

int main() {
	for ( int ix = 0; ix < iterations; ++ix ) func();
	return 0;
}
