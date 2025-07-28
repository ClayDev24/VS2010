#pragma once
#include <stdarg.h>
#include <iostream>
#include <stdio.h>
#include "defines.h"

// Following the format specification is a variable list of arguments.
// Each argument corresponds to a format character in the format string to which the szTypes parameter points
static  void ShowVar(char *szTypes, ...) {
	using namespace std;
	va_list list;
	//int i;
	//  szTypes is the last argument specified; you must access
	//  all others using the variable-argument macros.
	va_start(list, szTypes);
	// Step through the list.
	for(int i=0; szTypes[i] != '\0'; ++i) {
		union Printable_t {
			int     i;
			float   f;
			char    c;
			char   *s;
		} Printable;

		switch(szTypes[i]) { // Type to expect.
		case 'i':
			Printable.i = va_arg(list, int);
			P_(Printable.i)
				break;
		case 'f':
			Printable.f = static_cast<float>(va_arg(list, double));
			P_(Printable.f)
				break;
		case 'c':
			Printable.c = va_arg(list, char);
			P_(Printable.c)
				break;
		case 's':
			Printable.s = va_arg(list, char*);
			P_(Printable.s)
				break;
		default:
			break;
		}
	}
	va_end(list);
}

static void _diferentType() {
	// ShowVar takes a format string of the form
	// "ifcs", where each character specifies the
	// type of the argument in that position.
	ShowVar( "fcsi", 32.4f, 'a', "Test string", 4 );
}