#include <stdio.h> // Standard C Lib.

void _fseek() {
	FILE *pFile = fopen("myfile.txt", "w");
	fputs("This is an apple.", pFile);
	fseek(pFile, 9, SEEK_SET);
	fputs(" sam", pFile);
	fclose(pFile);
}