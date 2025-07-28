#pragma once

#define BUFFSZ 100

static void _constants() {
	// C => A const var ALWAYS occupies storage n its global visible.
	const int size = 100; // C/C++ => Storage allocated. C compiler cant know its value at compile time.
	char buf[size];	      // C++ => A const ain't necessarily create storage.

	memset(buf, 0, 100*sizeof(buf[0]));
	//const int bufsize;		// C => Declaration. C - There's storage allocated somewhere (defaults to external linkage for consts).
	//extern const int bufsize;	// C/C++ => C++ Defaults to internal linkage. 'extern' keyword to acomplish the above C statement

	// C approuch to const is not very useful, and if you want to use a named value inside a constant expression (one that must be 
	// evaluated at compile time), C almost forces you to use #define in the preprocessor:
	//char buf[BUFFSZ];
}