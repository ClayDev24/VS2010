// A super-variable
#pragma once
#include <iostream>

class SuperVar {	
	enum { // Untagged enum (no type name):
		character,
		integer,
		floating_point
	} vartype;  // Define one right away after declaration
	// Used when there's no need 2 declare another instance o'it ahead in the code.
	// Anonymous union:
	union {	// no type name...
		char c;
		int i;
		float f;
	}; // ...no variables names
public:
	SuperVar(char ch);
	SuperVar(int ii);
	SuperVar(float ff);
	void print();
};

SuperVar::SuperVar(char ch) {
	vartype = character;
	// Anonymous union access just as ordinary variables:
	c = ch; // w/out dot operator: x.c
	// Occupies the same storage space as int i | float f below
}

SuperVar::SuperVar(int ii) {
	vartype = integer;
	i = ii; // Occupies the same storage space as char c above | float f below
}

SuperVar::SuperVar(float ff) {
	vartype = floating_point;
	f = ff; // Occupies the same storage space as char c | int i above
}

void SuperVar::print() {
	switch (vartype) {
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

static void _untagged() {
	SuperVar A('c'), B(12), C(1.44F);
	A.print();
	B.print();
	C.print();
}