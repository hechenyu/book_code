#include <algorithm>
#include <list>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class size_compare {
public:
	bool operator()( const string &a, const string &b ) 
	{
		return a.length() <= b.length();
	}
};

int main()
{
	string arr1[] = { "Piglet", "Pooh", "Tigger" };
	string arr2[] = { "Piglet", "Pooch", "Eeyore" };

	bool res;
	// �ڶ���Ԫ��ֵΪ false
	// Pooch С�� Pooh
	// �ڶ���Ԫ��ֵҲΪ false
	res = lexicographical_compare( arr1, arr1+3,
		arr2, arr2+3 );
	assert( res == false );

	// ֵΪ true: ilist2 ÿ��Ԫ�ص�
	// ���ȶ�С�ڻ����
	// ��Ӧ�� ilist1 ��Ԫ��
	list< string > ilist1( arr1, arr1+3 );
	list< string > ilist2( arr2, arr2+3 );
	res = lexicographical_compare(
		ilist1.begin(), ilist1.end(),
		ilist2.begin(), ilist2.end(), size_compare() );
	assert( res == true );
	cout << "ok: lexicographical_compare succeeded!\n";

	return 0;
}
