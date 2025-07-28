#include <stdio.h> // Standard C Lib.
#include <stdarg.h>

void PrintFError(char *format, ...) {
	char buffer[256];
	va_list args;
	va_start(args, format);
	vsprintf(buffer, format, args);
	perror(buffer);
	va_end(args);
}

void _vsprintf() {	
	char szFileName[] = "myfile.txt";
	int firstchar = (int)'#';
	FILE *pFile = fopen(szFileName, "r");

	if(!pFile)
		PrintFError("Error opening '%s'",	szFileName);
	else 
		fclose(pFile); // file successfully open
}