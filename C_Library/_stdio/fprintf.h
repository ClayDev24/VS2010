#include <stdio.h> // Standard C Lib.

void _fprintf() {
	int  i;
	char name[100];
	FILE *pFile = fopen("myfile2.txt", "w+");

	for(i=0; i<3; i++) {
		puts("please, enter a name: ");
		gets(name);
		fprintf(pFile, "Name %d [%-10.10s]\n", i, name);
	}
	fclose(pFile);
}