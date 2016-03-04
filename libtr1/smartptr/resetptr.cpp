#include <tr1/memory>

#include "sputil.h"

using std::tr1::shared_ptr;
using std::cout;

class FreeResource {
public:
	void operator ()(resource *res)
	{
		cout << "delete resource: ";
		if (res != NULL)
			cout << *res;
		cout << "\n";
		delete res;
	}
};

int main()
{
    shared_ptr<resource> sp0;
    show("empty object before reset", sp0);

    sp0.reset(new resource(1), FreeResource());
    show("empty object after reset", sp0);

    sp0.reset(new resource(2), FreeResource());
    show("non-empty object after reset", sp0);

    return 0;
}
