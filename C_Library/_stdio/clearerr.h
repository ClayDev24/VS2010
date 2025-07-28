#include <stdio.h> // Standard C Lib.

void _clearerr() {
	FILE *pFile;
	pFile = fopen("myfile.txt", "r");
	if(!pFile)
		perror("Error opening file");
	else {
		// ERROR: Opened jus'for readin'operations:
		fputc('x', pFile);
		if(ferror(pFile)) {
			printf("Error Writing to myfile.txt\n");
			clearerr(pFile);
		}
		fgetc(pFile);
		if(!ferror(pFile))
			printf("No errors reading myfile.txt\n"); 
		fclose(pFile);
	}
}