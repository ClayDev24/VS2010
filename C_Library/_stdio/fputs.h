#include <stdio.h> // Standard C Lib.

void _fputs() {
	FILE *pFile = fopen("mytext.txt", "a");
	char str[256];	
	// Append a line at the end o'file each time it runs:
	printf("Enter a line to append to file: ");
	fgets(str, 255, stdin);	
	fputs(str, pFile);
	fclose(pFile);
}