#include <stdio.h> // Standard C Lib.

void _rewind() {
	int i;
	char buffer[27];
	FILE *pFile = fopen("myfile.txt", "w+");
	for(i='A'; i<='Z'; i++)
		fputc(i, pFile);
	rewind(pFile);
	fread(buffer, 1, 26, pFile);
	buffer[26] = '\0';
	puts(buffer);

	fclose(pFile);
}