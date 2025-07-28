#include <stdio.h> // Standard C Lib.

void _ferror() {
	FILE *pFile;
	pFile = fopen("ferror.h", "r"); // Open for readin' only
	if(!pFile)
		perror("Error opening file");
	else {
		fputc('x', pFile); // Tryin' to write in a read-opened file.
		if(ferror(pFile))  // Thus generatin' a error
			printf("Error Writing to ferror.h\n");
		fclose(pFile);
	}
}