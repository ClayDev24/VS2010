#include <stdio.h>	// Standard C lib.
#include <stdlib.h>	// Standard C lib.
//#include <cstdio>	// Standard C lib in C++ lib.
//#include <cstdlib>// Standard C lib in C++ lib.
//using namespace std; // Used with Borland C++ compiler.

void fnExit1(void) {
	puts("Exit function 1.");
}

void fnExit2(void) {
	puts("Exit function 2.");
}

void exit_abort() {
// exit:
	FILE *pFile = fopen("myfile.txt", "r");
	if(!pFile) {
		printf("Error opening file...\n");
		exit(EXIT_FAILURE); // Or MACRO EXIT_SUCCESS
		// Or use abort instead:
		//abort(); 
	} else
		fclose(pFile);
// atexit:
	atexit(fnExit1);
	atexit(fnExit1); // Can be scheduled more than once.
	atexit(fnExit2);
	puts("Main function.");
}