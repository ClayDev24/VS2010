#pragma once
#include <iostream>
//#include "untagged.h"
#define enum_on

class SuperV {	
#ifdef enum_on
	enum { // Untagged enum (no type name):
		character,
		integer,
		floating_point
	} vartype;  // Define one right away after declaration
	// Used when there's no need 2 declare another instance o'it ahead in the code.
#endif
	// Anonymous union:
	union {	// no type name...
		char  c;
		int   i;
		float f;
	}; // ...no variables names
public:
	SuperV(char ch);
	SuperV(int ii);
	SuperV(float ff);
	void print();
	inline void size() { std::cout << "sizeof(vartype): " << sizeof(vartype) << std::endl; }
};

SuperV::SuperV(char ch) {
#ifdef enum_on
	vartype = character;
#endif
	// Anonymous union access just as ordinary variables:
	c = ch; // w/out dot operator: x.c
	// Occupies the same storage space as int i | float f below
}

SuperV::SuperV(int ii) {
#ifdef enum_on
	vartype = integer;
#endif
	i = ii; // Occupies the same storage space as char c above | float f below
}

SuperV::SuperV(float ff) {
#ifdef enum_on
	vartype = floating_point;
#endif
	f = ff; // Occupies the same storage space as char c | int i above
}

void SuperV::print() {
	switch(vartype) {
	case character:
		std::cout << "character: " << c << "\n";
		break;
	case integer:
		std::cout << "integer  : " << i << "\n";
		break;
	case floating_point:
		std::cout << "float    : " << f << "\n";
		break;
	}
}

static void _save_space() {
	using namespace std;
	SuperV A('c'), B(12), C(1.44F);
	cout << "sizeof(SuperVar): " << sizeof(A) << endl;
	A.size();
	cout << "sizeof(char) : " << sizeof(char)  << endl;
	cout << "sizeof(int)  : " << sizeof(int)   << endl;
	cout << "sizeof(float): " << sizeof(float) << endl;
}