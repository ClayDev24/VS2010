#include <stdio.h>	// Standard C lib.
#include <string.h>	// Standard C lib.
//#include <cstdio>	// Standard C lib in C++ lib.
//#include <cstring>// Standard C lib in C++ lib.
//using namespace std; // Used with Borland C++ compiler.

void _memchr() {
	char *pch;
	char *str = "Example string";
// MEMCHR: Locates char in block o'memo:
	pch = (char*)memchr(str, 'p', strlen(str)); // (c_str, char, num bytes searched).
	if(pch) // NULL if not find.
		printf("'p' found at position %d.\n", pch-str+1);
	else
		printf("'p' not found.\n");
	printf("%s", pch);
}