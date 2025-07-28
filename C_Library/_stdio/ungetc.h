#include <stdio.h> // Standard C Lib.

void _ungetc() {
	int c;
	char buffer[256];
	FILE *pFile = fopen("myfile.txt", "rt");

	if(!pFile)
		perror("Error opening file");
	else {
		while(!feof(pFile)) {
			c = getc(pFile);
			if(c=='a')
				ungetc('b', pFile);
			else
				ungetc(c, pFile);
			fgets(buffer, 255, pFile);
			fputs(buffer, stdout);
		}
		fclose(pFile);
	}
}