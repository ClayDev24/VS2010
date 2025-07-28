#include <stdio.h> // Standard C Lib.

void _fputc() {
	FILE *pFile = fopen("alphabet.txt", "w");
	char c = 'z';
	if(pFile)
		fputc((int)c, pFile);	
	fclose(pFile);
}