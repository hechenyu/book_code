#include <string>
#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;
using std::string;

int main()
{
	size_t ia;
	ia = sizeof( ia ); // ok
	ia = sizeof ia; // ok
	// ia = sizeof int; // ����
	ia = sizeof( int ); // ok
	int *pi = new int[ 12 ];
	cout << "pi: " << sizeof( pi )
		 << " *pi: " << sizeof( *pi )
		 << endl;
	// һ��string �Ĵ�С������ָ���ַ����ĳ����޹�
	string st1( "foobar" );
	string st2( "a mighty oak" );
	string *ps = &st1;
	cout << "st1: " << sizeof( st1 )
		 << " st2: " << sizeof( st2 )
		 << " ps: " << sizeof( ps )
		 << " *ps: " << sizeof( *ps )
		 << endl;
	cout << "short :\t" << sizeof(short) << endl;
	cout << "short* :\t" << sizeof(short*) << endl;
	cout << "short& :\t" << sizeof(short&) << endl;
	cout << "short[3] :\t" << sizeof(short[3]) << endl;
}
