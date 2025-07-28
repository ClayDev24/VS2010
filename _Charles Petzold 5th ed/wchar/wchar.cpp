// wchar.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "string.h"
//#include "wchar.h"

void wcharfunc(void) {
	static char a[] = "Hello!";
	printf("\t%s %i-byte(s)\n", a, sizeof(a));
}

int main(int argc, char* argv[])
{
// ANSII CHAR: char
	printf("ANSII CHAR: char\n");
	char buffer[10];
	char c = 'A';
	char *p = &c;
	char *p2 = "Hello!";
	char a[10];
	a[0] = 'c';
	a[1] = 'l';
	a[2] = 'a';
	a[3] =   0;
	char a2[] = "Hello!";
	sizeof(c, buffer, 10);
	printf("\t%X %i-byte(s)\n",  c, sizeof(c));
	printf("\t%c %i-byte(s)\n",  c, sizeof(c));
	printf("\t%c %i-byte(s)\n", *p, sizeof(*p));
	printf("\t%p %i-byte(s)\n",  p, sizeof(p));
	printf("\t%s %i-byte(s)\n", p2, sizeof(p2));
	printf("\t%s %i-byte(s)\n", a2, sizeof(a2));
	printf("\t%s %i-bytes in memory\n", a, sizeof(a));
	printf("\t%s %i-bytes its length\n", a, strlen(a));
	wcharfunc();

// WIDE CHAR: wchar_t
	printf("\nWIDE CHAR: wchar_t\n");
	wchar_t w = L'A'; // The L symbol is optional since it's only one character. Compiler'll assign 2 bytes long char.
	wchar_t *pw = &w; // Pointer to wide character.
	char *cc = (char*)pw;
	printf("\tchar:%c dec:%i hex:%X\n", w, w, w);
	printf("\t%i-bytes %i-bytes\n", sizeof(wchar_t), sizeof(unsigned short));
	printf("\t%X \n", cc[0]); // Intel stores it reverse sided in memory!
	printf("\t%X \n", cc[1]);

	// Pointers to wide characters strings:
	wchar_t pw2[] = L"Hello!";	 // L stands for LONG. The compiler assigns each character as 2 bytes long
	printf("\t%i-bytes \n", sizeof(pw2));// 2 bytes per char + 2 bytes per zero = 14 bytes allocated in memory.
	printf("\twchar:%c hex:%X\n", pw2[1], pw2[1]);

	wchar_t *pw3 = L"Hello!";
	printf("\t%i-bytes long\n", wcslen(pw3));
	wprintf(L"\t%s \n", pw3);

// WIDE-CHARACTER Library Functions:
	

	return 0;
}

