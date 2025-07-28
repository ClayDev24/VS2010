#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.

void _strpbrk() {
	char src[]  = "This is a sample string";
	char keys[] = "aeiou";
	char *pch;
	printf("Vowels in '%s': ", keys);
	pch = strpbrk(src, keys);
	while(pch) {
		printf("%c ", *pch);
		pch = strpbrk(pch+1, keys);
	}
	puts("\n");
}