#include <stdio.h> // Standard C Lib.

void _fflush() {
	char mybuffer[80];
	FILE *pFile;
	pFile=fopen("myfile.txt", "rb");
	if(!pFile)
		perror("Error opening file");
	else {
		fputs("test", pFile);
		fflush(pFile);  // flushing or repositioning required
		fgets(mybuffer, 80, pFile);
		puts(mybuffer);
		fclose(pFile);
	}
}