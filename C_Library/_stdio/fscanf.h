#include <stdio.h> // Standard C Lib.

void _fscanf() {
	char  str[80];
	float f;
	FILE *pFile = fopen("myfile.txt", "w+");

	fprintf(pFile, "%f %s", 3.1416, "PI");
	rewind(pFile); // Try to comment out this line n' see what's happen.
	fscanf(pFile, "%f", &f);
	fscanf(pFile, "%s", str);
	fclose(pFile);
	printf("I have read: %f and %s \n", f, str);
}