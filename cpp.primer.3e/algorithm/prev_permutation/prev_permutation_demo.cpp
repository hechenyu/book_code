#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

// ���:
// n d a	n a d	d n a	d a n	a n d	a d n

int main()
{
	vector< char > vec( 3 );
	ostream_iterator< char > out_stream( cout, " " );
	vec[0] = 'n'; vec[1] = 'd'; vec[2] = 'a';
	copy( vec.begin(), vec.end(), out_stream ); cout << "\t";

	// ���� "dan" ����������
	while( prev_permutation( vec.begin(), vec.end() )) {
		copy( vec.begin(), vec.end(), out_stream );
		cout << "\t";
	}
	cout << "\n\n";
}
