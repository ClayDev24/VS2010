#include <stdio.h> // Standard C Lib.

void _getchar() {
	char c;
	puts("Enter text. Include a dot ('.') in a sentence to exit:");
	do {
		c = getchar(); // Read char from standard input (stdin).
		// Same as:
		//c = getc(stdin);
		putchar(c);	 // Write char to stadanrd output(stdout).
	} while(c!='.');
}