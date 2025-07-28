#include <stdio.h> // Standard C Lib.
#include <stdlib.h>// Standard C Lib.
/* fread example: Read a complete binary file */

void _fread() {
	char *bufout;
	char bufin[] = "claybom";
	size_t result;
	long lSize;

	FILE *pFile = fopen("myfile.bin", "wb");
	fwrite(bufin, sizeof(char), sizeof(bufin) ,pFile);
	fclose(pFile);
  	
	pFile = fopen("myfile.bin" , "rb");
	if(pFile==NULL) {
		fputs("File error", stderr);
		exit(1);
	}
	// obtain file size:
	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind(pFile);
	// allocate memory to contain the whole file:
	bufout = (char*)malloc(sizeof(char)*lSize);
	if(bufout==NULL) {
		fputs("Memory error", stderr);
		exit(2);
	}
	// copy the file into the buffer:
	result = fread(bufout, sizeof(char), lSize, pFile);
	if(result!=lSize) {
		fputs("Reading error", stderr);
		exit(3);
	}
	printf("%s\n", bufout);	
	/* the whole file is now loaded in the memory buffer. */	
	fclose (pFile);
	free(bufout);
}