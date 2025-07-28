//#include "vld.h" // No memory leaks DETECTED!
#pragma once
#include <iostream>
#include <stdio.h>  // printf
#include "_colour.h"
using namespace std;
using namespace utils;

#define PRINT(x)			PrintColour("", 0, FGI); \
								printf("%*s", -11,  #x); \
							PrintColour("", 0, FRI); \
								cout << ": " << sizeof(x) << "-byte(s)\n";

#define PRINT2(x, x2, x3)	PrintColour("", 0, FGI); \
								printf("%*s", -18,  #x); \
							PrintColour("", 0, FRI); \
								cout << ": " << sizeof(x) << #x2; \
							PrintColour("", 0, FY); \
								cout << " = 0.." << x3 << "\n";
					

volatile int char_min = CHAR_MIN;

static void _dataTypes() {
	// Literal constants defaults to int:
	// 75   // int
	// 75u  // unsigned int
	// 75l  // long
	// 75us // unsigned long
	char          ch;
	unsigned char c  = 0xFF; // %1000_0000	
	signed char   sc;
	bool          b  = true;
	short         s  = 0xFFFF;		// %1000_0000_0000_0000
	short int     si = 0xFFFF;		// = short
	int           i  = 0xFFFFFFFF;	// %1000_0000_0000_0000_0000_0000_0000_0000
	long          l  = 0xFFFFFFFF;
	long int      li = 0xFFFFFFFF;	// = long
	long long     ll = 0xFFFFFFFFFFFFFFFF;	// = long long => 18.446.744.073.709.551.615;

	// Float point numbers default to float:
	// 3.14159L // long double
	// 6.02e23f // float
	float		  f;
	double		  d;
	long float    lf;
	//short float   sf; // NOT ALLOWED
	long double   ld;
	//short double  sd; // NOT ALLOWED

// Specifiers: long, short, signed and unsigned
// When you are modifying an int with short or long the keyword int is optional:
	PrintColour("<< DATA TYPES >>\n\n", BRI, 0);
	PRINT(char)
	PRINT(bool)
	PRINT(short)
	PRINT(short int) // int is redundant
	PRINT(int)
	PRINT(long)
	PRINT(long int) // int is redundant
	PRINT(long long)
	// Floatin' point numbers are always signed:
	PRINT(float)
	PRINT(double)
	PRINT(long float)
	PRINT(long double)
	
	//cout << endl << "UNSIGNED DATA TYPES:\n\n"; // int is redundant:
	PrintColour("\n<< UNSIGNED DATA TYPES >>\n\n", BRI, 0);
	PRINT2(unsigned char,      -byte(s), (int)c)
	PRINT2(unsigned short,     -byte(s), (unsigned short)s)
	PRINT2(unsigned short int, -byte(s), (unsigned short int)si)
	PRINT2(unsigned int,       -byte(s), (unsigned int)i)
	PRINT2(unsigned long,      -byte(s), (unsigned long)l)
	PRINT2(unsigned long int,  -byte(s), (unsigned long int)li)
	PRINT2(unsigned long long, -byte(s), (unsigned long long)ll)

	cout << "\nSIGNED DATA TYPES:\n\n"; // Defaults to signed:
	cout << "signed char      : " << sizeof(signed char)      << "-byte(s) = " << (int)0x80            << ".." << 0x7F << endl;
	cout << "signed short     : " << sizeof(signed short)     << "-byte(s) = " << (short)0x8000        << ".." << 0x7FFF << endl;
	cout << "signed short int : " << sizeof(signed short int) << "-byte(s) = " << (short)0x8000         << ".." << 0x7FFF << endl;
	cout << "signed int       : " << sizeof(signed int)       << "-byte(s) = " << (signed int)0x80000000 << ".." << 0x7FFFFFFF << endl;
	cout << "signed long      : " << sizeof(signed long)      << "-byte(s) = " << (long)0x80000000         << ".." << 0x7FFFFFFF << endl;
	cout << "signed long int  : " << sizeof(signed long int)  << "-byte(s) = " << (long)0x80000000           << ".." << 0x7FFFFFFF << endl;
	cout << "signed long long : " << sizeof(signed long long) << "-byte(s) = " << (long long)0x8000000000000000 << ".." << 0x7FFFFFFFFFFFFFFF << endl << endl;

    cout << "Size of boolean type is " << sizeof(bool) << " byte(s)\n\n";

    cout << "char: " << CHAR_BIT << "-bits  :" << SCHAR_MIN << ".." << SCHAR_MAX << endl;
    cout << "Unsigned char : 0.." << UCHAR_MAX << endl;
	cout << "Default char is ";
	if (char_min < 0)
        cout << "signed";
    else if (char_min == 0)
        cout << "unsigned";
    else
        cout << "non-standard";
    cout << endl << endl;
    cout << "Signed short  : " << SHRT_MIN << ".." << SHRT_MAX  << endl;
    cout << "Signed int    : " << INT_MIN  << ".." << INT_MAX   << endl;
	cout << "Signed long   : " << LONG_MIN << ".." << LONG_MAX  << endl;
    cout << "Unsigned short: 0.."                  << USHRT_MAX << endl;
    cout << "Unsigned int  : 0.."                  << UINT_MAX  << endl;
    cout << "Unsigned long : 0.."                  << ULONG_MAX << endl << endl;
}