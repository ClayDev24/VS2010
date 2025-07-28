#include <stdio.h> // Standard C Lib.

void _ftell() {
	FILE *pFile;
	long size;
	size_t result;

	char bufout[] = "claybom";
	pFile = fopen("myfile.bin", "wb");
	fwrite(bufout, sizeof(char), sizeof(bufout) ,pFile);
	fclose(pFile);
	
	pFile = fopen("myfile.bin", "rb"); // read binary
	if (pFile==NULL)
		perror("Error opening file");
	else {
		//fseek(pFile, 0, SEEK_SET);// begin o' file
		fseek(pFile, 0, SEEK_END);	// end o' file
		size = ftell(pFile); // Returns the cur val o'the pos o'the stream.
		fclose(pFile);
		printf("Size of myfile.txt: %ld bytes.\n", size);
	}
}