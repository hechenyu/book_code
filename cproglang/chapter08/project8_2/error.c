/* error.c */
#include <stdio.h>
#include <stdarg.h>

/* error函数：打印一个出错信息，然后终止 */
void error(char *fmt, ...)
{
	va_list args;
	
	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}
