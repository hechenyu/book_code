#include <iostream>
#include "singleton.h"
#include "shlibfirstexports.h"
using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

int shlibfirst_function(void)
{
	cout << __FUNCTION__ << ":" << endl;
    Singleton& singleton = Singleton::GetInstance();
    singleton.DoSomething();
    return 0;
}

#ifdef __cplusplus
}
#endif // __cplusplus
