#include <stdio.h> // Standard C Lib.

void _feof() {
	FILE *pFile;
	pFile = fopen("feof.h", "rb");
	if(!pFile)
		perror("Error opening file");
	else {
		while(!feof(pFile))
			printf("%c", fgetc(pFile));
		fclose(pFile);
	}
}