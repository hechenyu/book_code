#include <stdio.h>

int staticlibsecond_function(int x)
{
    printf("%s\n", __FUNCTION__);
    return (x+1);
}

int staticlib_duplicate_function(int x)
{
    printf("%s\n", __FUNCTION__);
    return (x+2);
}

