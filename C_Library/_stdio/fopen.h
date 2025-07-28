#include <stdio.h> // Standard C Lib.

void showFile(char *name, char *mode);

void _fopen() {
// TEXT FILE OPERATIONS:
	// w: Open 4 WRITING. Exist = erased. Not exist = CREATED:
	showFile("myfile.txt", "w");
	// r: Open 4 READING. NOT exist = ERROR.
	showFile("myfile.txt", "r");
	// a: WRITING operations APPEND data at the END o'file. NOT exist = created:
	showFile("myfile.txt", "a");
	// r+: READING n' WRITING. If NOT exist = ERROR. If exists = Start writin at the BEGINNING o'file:
	showFile("myfile.txt", "r+");
	// w+: READING n' WRITING. If NOT exist = created. If exists = erased.
	showFile("myfile.txt", "w+");
	// a+: READING n' APPENDING. If exists = All writin' operations are performed at the end of the file,
	// protectin' the previous content to be overwritten. You can reposition (fseek, rewind) the internal pointer
	// to anywhere in the file for readin', but writing' operations will move it back to the end o'file.
	// NOT exists = CREATED:
	showFile("myfile.txt", "a+");

// BINARY FILE OPERATIONS:
	showFile("myfile.txt", "wb");
	showFile("myfile.txt", "rb");
	showFile("myfile.txt", "ab");
	showFile("myfile.txt", "r+b"); // same as rb+
	showFile("myfile.txt", "w+b"); // same as wb+
	showFile("myfile.txt", "a+b"); // same as ab+
}

void showFile(char *name, char *mode) {
	static int cnt = 0;
	char line[128];
	fpos_t pos;
	FILE *pFile = fopen(name, mode);
	sprintf(line, "Example line: %i\n", ++cnt);
	if(pFile==NULL)
		perror("Error opening file");
	else {
		// Tryin' to write:
		fputs(line, pFile);
		if(ferror(pFile)) {
			printf("Error Writin' to %s, mode: %s, line: %s\n", name, mode, line);
			clearerr(pFile);
		}
		// Tryin' to read:
		rewind(pFile);
		while(!feof(pFile)) {
			printf("%c", getc(pFile));		
			if(ferror(pFile)) {
				printf("Error Readin' from %s, mode: %s\n", name, mode); 
				break;
			}
		}
		fclose(pFile);
	}
}