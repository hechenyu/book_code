#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
// ��׼ C++ ֮ǰ�� <iostream> �﷨
#include <iostream>

using namespace std;

class GreaterThan {
public:
	GreaterThan( int sz = 6 ) : _size( sz ){}
	int size() { return _size; }
	bool operator()( const string &s1 )
	{ return s1.size() > _size; }

private:
	string::size_type _size;
};

class PrintElem {
public:
	PrintElem( int lineLen = 8 ) : _line_length( lineLen ), _cnt( 0 ) {}
	void operator()( const string &elem )
	{
		++_cnt;
		if ( _cnt % _line_length == 0 )
		{ cout << '\n'; }
		cout << elem << " ";
	}
	
private:
	int _line_length;
	int _cnt;
};

class LessThan {
public:
	bool operator()( const string & s1,	const string & s2 )
	{ return s1.size() < s2.size(); }
};

typedef vector<string> textwords;

void process_vocab( vector<textwords>*pvec )
{
	if ( ! pvec ) {
	// ����������Ϣ
	return;
	}

	vector< string > texts;
	vector<textwords>::iterator iter;
	for ( iter = pvec->begin(); iter != pvec->end(); ++iter )
		copy( (*iter).begin(), (*iter).end(), back_inserter( texts ));
	
	// ���� texts ��Ԫ��
	sort( texts.begin(), texts.end() );
	// ok, ��������һ��������ʲô
	for_each( texts.begin(), texts.end(), PrintElem() );
	cout << "\n\n"; // ֻ�Ƿָ���ʾ���
	// ɾ���ظ�Ԫ��
	vector<string>::iterator it;
	it = unique( texts.begin(), texts.end() );
	texts.erase( it, texts.end() );
	// ok, ����������һ������������ʲô��
	for_each( texts.begin(), texts.end(), PrintElem() );
	cout << "\n\n";
	
	// ����ȱʡ�ĳ��� 6 ����Ԫ��
	// stable_sort() �������Ԫ�ص�˳��
	stable_sort( texts.begin(), texts.end(), LessThan() );
	for_each( texts.begin(), texts.end(), PrintElem() );
	cout << "\n\n";
	
	// �������ȴ���6 ���ַ����ĸ���
	int cnt = 0;
	// count �Ĺ�ʱ��ʽ������׼ C++ �Ѿ��ı�����
	cnt = count_if( texts.begin(), texts.end(), GreaterThan());
	cout << "Number of words greater than length six are "
		<< cnt << endl;
	
	static string rw[] = { "and", "if", "or", "but", "the" };
	vector<string> remove_words( rw, rw+5 );
	vector<string>::iterator it2 = remove_words.begin();
	for ( ; it2 != remove_words.end(); ++it2 )
	{
		int cnt = 0;
		// count �Ĺ�ʱ��ʽ������׼ C++ �Ѿ��ı�����
		cnt = count( texts.begin(), texts.end(), *it2);
		cout << cnt << " instances removed: "
			<< (*it2) << endl;
		texts.erase(remove(texts.begin(),texts.end(),*it2),	texts.end());
	}
	cout << "\n\n";
	for_each( texts.begin(), texts.end(), PrintElem() );
}

// difference_type �����ܹ�����һ������������ iterator �ļ������
// ���������������, �� string vector �� ...
// ͨ��, ��ȱʡ����
typedef vector<string>::difference_type diff_type;
// ��׼ C++ ֮ǰ��ͷ�ļ��﷨
#include <fstream>

int main()
{
	vector<textwords> sample;
	vector<string> t1, t2;
	string t1fn, t2fn;
	// Ҫ���û������ļ�
	// ʵ���еĳ���Ӧ����������
	cout << "text file #1: "; cin >> t1fn;
	cout << "text file #2: "; cin >> t2fn;
	// ���ļ�
	ifstream infile1( t1fn.c_str());
	ifstream infile2( t2fn.c_str());
	// iterator ��������ʽ
	// ͨ��, diff_type ��ȱʡ�ṩ
	istream_iterator< string > input_set1( infile1 ), eos;
	istream_iterator< string > input_set2( infile2 );
	// iterator ��������ʽ
	copy( input_set1, eos, back_inserter( t1 ));
	copy( input_set2, eos, back_inserter( t2 ));
	sample.push_back( t1 ); sample.push_back( t2 );
	process_vocab( &sample );
	
	return 0;
}
