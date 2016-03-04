
#include <cstring>
#include <cassert>
#include <iomanip>
#include "String.h"

using std::istream;
using std::ostream;

// ȱʡ���캯��
//inline 
String::String()
{
	init(0);
}

//inline 
String::String(const char *str)
{
	init(str);
}

// �������캯��
//inline 
String::String(const String &rhs)
{
	init(rhs);
}

//inline 
String::~String()
{
	delete [] _string;
}

//inline 
String &String::operator=(const char *s)
{
	delete [] _string;
	init(s);
	return *this;
}

//inline 
String &String::operator=(const String &rhs)
{
	if (this != &rhs) {
		delete [] _string;
		init(rhs);
	}
	return *this;
}

//inline 
bool String::operator==(const String &rhs)
{
	if (_size != rhs._size)
		return false;
	return strcmp(_string, rhs._string) ? false : true;
}

//inline 
bool String::operator==(const char *s)
{
	return strcmp(_string, s) ? false : true;
}

//inline 
char &String::operator[](int elem)
{
	assert(elem >= 0 && elem < _size);
	return _string[elem];
}

//inline 
istream &operator>>(istream &is, String &s)
{
	// �˹��������4096���ַ�
	const int limit_string_size = 4096;
	char inBuf[limit_string_size];
	
	// setw()��iostream���һ����
	// ���Ʊ���ȡ���ַ�����Ϊlimit_string_size-1
	using std::setw;
	is >> setw(limit_string_size) >> inBuf;
	
	s = inBuf;	// String::operator=(const char *);
	return is;
}

//inline 
ostream &operator<<(ostream &os, const String &s)
{
	return os << s.c_str();
}

//inline 
void String::init(const char *s)
{
	if (!s) {
		_size = 0;
		_string = 0;
	} else {
		_size = strlen(s);
		_string = new char[_size+1];
		strcpy(_string, s);
	}
}

//inline
void String::init(const String &rhs)
{
	_size = rhs._size;
	if (!rhs._string)
		_string = 0;
	else {
		_string = new char[_size+1];
		strcpy(_string, rhs._string);
	}
}