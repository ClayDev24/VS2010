#include <stdio.h> // Standard C Lib.

void _fgets() {
	FILE *pFile = fopen("fgets.h", "r");
	char line[256];
	int i;
	
	if(!pFile)
		perror("Error opening file");
	else {
		while(fgets(line, 256, pFile))
			printf("%s", line);
		fclose(pFile);
	}
	printf("Enter a line: ");
	fgets(line, 256, stdin);
	printf("Yave entered %s.\n", line);
}