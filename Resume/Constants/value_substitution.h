#pragma once
#include <iostream>
// old C style: There's not type info. (buggy code)
#define BUFSIZE 100 // BUFSIZE is a name that only exists in preprocessing (no storage, any translation units can use it).
// new C++ Safe
const int bufsize = 100; // C++ approuch

// Should always use constants instead of #define's preprocessor val substitution.
// Internal linkage (file scoped visibility): (No storage, but definition in symble table)
const float   ZERO  = 0.0;		  // In C++ constants must always have an initialization value.
const int     octal = 017;		  // leading 0 is treated as octal number
const int     hexa  = 0xA;		  // Hexadecimal
const double  db    = 1e4;		  // Scientific Notation
const double  db2   = -1.159e-77; // Defaults to double
const double  db3   = 47.0F;	  // Forces float implicity conversion
const double  db4   = 47.0L;	  // Forces long double "     "
const char    ch    = 'a';		  // char
const char    ch2   = '\113';	  // octal
const char    ch3   = '\x4A';	  // hexa

const unsigned char uc = 0;
const signed   char sc = 'a';
const bool          b1 = true;
const short         s1 = 0;
const short int     si = 0;	// = short
const long          cl = 0;
const long  int     li = 0;	// = long
//const long  float   lf = 0; // bcc32 error: Too many types in declaration
const long  double  ld = 0;

static void _value_substitution() {
	using namespace std;
	cout << ZERO  << endl;
	cout << octal << endl;
	cout << hexa  << endl;
	cout << db    << endl;
	cout << db2   << endl;
	cout << db3   << endl;
	cout << db4   << endl;
	cout << ch    << endl;
	cout << ch2   << endl;
	cout << ch3   << endl;
}

// HINTS:
// Because of the subtle bugs that the preprocessor might introduce (lack of type checking),
// you SHOUD ALWAYS USE  const INSTEAD of #define value substitution.