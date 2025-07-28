#include <stdio.h> // Standard C Lib.

void _fgetpos() {
	FILE *pFile = fopen("fgetpos.h", "r");
	fpos_t pos;
	int n;
	
	if(!pFile)
		perror("Error opening file");
	else {
		printf("1st character is %c\n", fgetc(pFile));
		fgetpos(pFile, &pos); // Get pos for char #2 and not change it
		for(n=0; n<3; n++) {
			fsetpos(pFile, &pos); // Get char #2 for 3 time. Comment out this line to keep on movin'...
			printf("2nd character is %c\n", fgetc(pFile));
		}
		fclose(pFile);
	}
}