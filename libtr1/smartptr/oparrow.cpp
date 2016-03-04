#include <tr1/memory>
#include <iostream>

using std::tr1::shared_ptr;
using std::cout;

struct S {
	int member;
};

int main()
{
	S *s = new S;
	s->member = 4;
	shared_ptr<S> sp(s);
	cout << sp->member << '\n';
	return 0;
}
