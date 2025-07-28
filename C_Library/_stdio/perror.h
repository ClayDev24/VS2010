#include <stdio.h> // Standard C Lib.

void _perror() {
	FILE *pFile = fopen("unexist.ent", "rb");
	if(!pFile)
		perror("The following error occurred");
	else
		fclose(pFile);
}