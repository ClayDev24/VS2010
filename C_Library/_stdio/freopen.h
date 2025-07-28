#include <stdio.h> // Standard C Lib.

void _freopen() {
	freopen("mytext.txt", "w", stdout);
	printf("This sentence is redirected to a file.");
	fclose(stdout);
}