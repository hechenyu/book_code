
#include <iostream>
#include "ArrayT.h"

using namespace std;

int main(int argc, char *argv[])
{
	const int array_size = 4;
	
	// elemType�����int
	Array<int> ia(array_size);
	
	// elemType�����double
	Array<double> da(array_size);
	
	// elemType�����char
	Array<char> ca(array_size);
	
	int ix;
	for (ix = 0; ix < array_size; ++ix) {
		ia[ix] = ix;
		da[ix] = ix * 1.75;
		ca[ix] = ix + 'a';
	}
	
	for (ix = 0; ix < array_size; ++ix) 
		cout << "[ " << ix << " ] ia: " << ia[ix]
			 << "\tca: " << ca[ix]
			 << "\tda: " << da[ix] << endl;
		 
    system("PAUSE");
    return EXIT_SUCCESS;
}
