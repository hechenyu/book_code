#include <cstdlib>
#include <iostream>
#include "String.h"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt =0, uCnt = 0,
		theCnt = 0, itCnt = 0, wdCnt = 0, notVowel = 0;
	
	// Ϊ��ʹ��operator==(const char *)
	// ���ǲ�������The("The")��It("It")
	String buf, the("the"), it("it");
	
	// ����operator>>(istream &, String &)
	while (cin >> buf) {
		++wdCnt;
		
		// ����operator<<(ostream &, const String &)
		cout << buf << ' ';
		
		if (wdCnt % 12 == 0)
			cout << endl;
		
		// ����String::operator==(const String &)��
		// String::operator==(const char *);
		if (buf == the || buf == "The")
			++theCnt;
		else if (buf == it || buf == "it")
			++itCnt;
		
		// ����String::size()
		for (int ix = 0; ix < buf.size(); ++ix) {
			// ����String::operator[](int)
			switch (buf[ix]) {
			case 'a': case 'A': ++aCnt; break;
			case 'e': case 'E': ++eCnt; break;
			case 'i': case 'I': ++iCnt; break;
			case 'o': case 'O': ++oCnt; break;
			case 'u': case 'U': ++uCnt; break;
			default: ++notVowel; break;
			}
		}
	}
	
	// ����operator<<(ostream &, const String &)
	cout << "\n\n"
		 << "Words read: " << wdCnt << "\n\n"
		 << "the/The: " << theCnt << '\n'
		 << "it/It: " << itCnt << "\n\n"
		 << "non-vowels read: " << notVowel << "\n\n"
		 << "a: " << aCnt << '\n'
		 << "e: " << eCnt << '\n'
		 << "i: " << iCnt << '\n'
		 << "o: " << oCnt << '\n'
		 << "u: " << uCnt << endl;
		 
    return 0;
}

