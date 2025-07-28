#include <stdio.h> // Standard C Lib.
#include <stdarg.h>

void WriteFormatted2(char *format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

void _vprintf() {
	WriteFormatted2("Call with %d variable argument.\n", 1);
	WriteFormatted2("Call with %d variable %s.\n", 2, "arguments");
}