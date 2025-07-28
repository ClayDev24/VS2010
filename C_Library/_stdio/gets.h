#include <stdio.h> // Standard C Lib.

void _gets() {
	char str[256];
	printf("Start typing a line: ");
	gets(str);
	printf("Your typed line    : %s\n", str);
}