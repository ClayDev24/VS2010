#include <stdio.h> // Standard C Lib.

void _fseekpos() {
	fpos_t pos;
	
	FILE *pFile = fopen("myfile.txt", "w");
	fgetpos(pFile, &pos); // Gets the beginnin' pos.
	fputs("That is a sample", pFile);
	fsetpos(pFile, &pos); // Sets the pos at beginnin'.
	fputs("This", pFile);
	fclose(pFile);
}