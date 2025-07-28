#if!defined __CONSTANTS_H__
#define     __CONSTANTS_H__

#define BUFFSZ 100

void _constants() {
	// C => A const var ALWAYS occupies storage n its global visible.
	const int bufsize = 100; // C/C++ => Storage allocated. C compiler cant know its value at compile time.
	//char buf[bufsize];	 // C++ => A const doesn't necessarily create storage.

	//const int bufsize;		// C => Declaration. C - There's storage allocated somewhere (defaults to external linkage for consts).
	//extern const int bufsize;	// C/C++ => C++ Defaults to internal linkage. 'extern' keyword to acomplish the above C statement

	// C approuch to const is not very useful, and if you want to use a named value inside a constant expression (one that must be 
	// evaluated at compile time), C almost forces you to use #define in the preprocessor:
	char buf[BUFFSZ];
}

#endif // __CONSTANTS_H__