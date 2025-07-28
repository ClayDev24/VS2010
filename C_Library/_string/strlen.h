#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strlen() {
	char szInput[256];
	printf("Enter a sentence: ");
	gets(szInput);
	printf("sizeof(szInput): %u chars long.\n", sizeof(szInput));
	printf("strlen(szInput): %u chars long.\n", strlen(szInput));
}