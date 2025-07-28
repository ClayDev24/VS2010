#include <stdio.h> // Standard C Lib.

void _getc() {
	int c;
	FILE *pFile = fopen("myfile.txt", "r");
	if(!pFile)
		perror("Error opening file");
	else {
		while((c=getc(pFile))!=EOF)
			printf("%c", c);
		fclose(pFile);
	}	
}