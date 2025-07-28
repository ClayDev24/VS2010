#include <stdio.h> // Standard C Lib.

void _fgetc() {
	FILE *pFile = fopen("fgetc.h", "r");
	int c;
	if(!pFile)
		perror("Error opening file");
	else {
		while((c = fgetc(pFile))!=EOF)
			printf("%c", c);
		fclose(pFile);
	}
}