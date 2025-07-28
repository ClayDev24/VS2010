#include <stdio.h> // Standard C Lib.

void _putchar() {
	char c;
	for(c='A'; c<='Z'; c++)
		putchar(c);
		// Same as:
		//putc(c, stdout);
}