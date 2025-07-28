#include <stdio.h> // Standard C Lib.

void _tmpfile() {
	FILE *pFile = tmpfile();
	// temporary file created. code here.
	fclose(pFile);
}