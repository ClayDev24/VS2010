#include <stdio.h> // Standard C Lib.

void _puts() {
	char str[] = "Hello world!";
	puts(str);
	// Same as, but w/out new char:
	//fputs(string, stdout);
}