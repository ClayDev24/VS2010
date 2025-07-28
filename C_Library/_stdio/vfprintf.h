#include <stdio.h> // Standard C Lib.
#include <stdarg.h>

void WriteFormatted(FILE *stream, char *format, ...) {
	va_list args;
	va_start(args, format);
	vfprintf(stream, format, args);
	va_end(args);
}

void _vfprintf(){
	FILE *pFile = fopen("myfile.txt", "w");
	
	WriteFormatted(pFile,"Call with %d variable argument.\n", 1);
	WriteFormatted(pFile,"Call with %d variable %s.\n", 2, "arguments");
	
	fclose(pFile);
}