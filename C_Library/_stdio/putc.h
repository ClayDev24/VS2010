#include <stdio.h> // Standard C Lib.

void _putc() {
	char c;
	FILE *pFile = fopen("alphabet.txt", "wt");
	for(c='A'; c<='Z'; c++)
		putc(c, pFile);    
	fclose(pFile);
}