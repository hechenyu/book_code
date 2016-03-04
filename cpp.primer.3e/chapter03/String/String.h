
#include <iostream>

using std::istream;
using std::ostream;

class String;

istream &operator>>(istream &, String &);
ostream &operator<<(ostream &, const String &);

class String {
public:
	// һ�����صĹ��캯��
	// �ṩ�Զ���ʼ������
	// String str1;				// String()
	// String str2("literal");	// String(const char *);
	// String str3(str2);		// String(const String &);
	
	String();
	String(const char *);
	String(const String &);
	
	// ��������: �Զ�����
	~String();
	
	// һ�����صĸ�ֵ������
	// str1 = str2;
	// str3 = "a string literal";
	
	String &operator=(const String &);
	String &operator=(const char *);
	
	// һ�����صĵ��ڲ�����
	// str1 = str2;
	// str3 = "a string literal";
	
	bool operator==(const String &);
	bool operator==(const char *);
	
	// ���ص��±������
	// str1[0] = str2[0];
	
	char &operator[](int);
	
	// ��Ա���ʺ���
	int size() {return _size;}
	char *c_str() const {return _string;}
	
private:
	int _size;
	char *_string;
};
