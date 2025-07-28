// A super-varia
#pragma once
#include <iostream>

class SuperVar {
	enum {
		character,
		integer,
		floating_point
	} vartype;  // Define one
	union {  // Anonymous union
		char c;
		int i;
		float f;
	};
public:
	SuperVar(char ch);
	SuperVar(int ii);
	SuperVar(float ff);
	void print();
};

SuperVar::SuperVar(char ch) {
	vartype = character;
	c = ch;
}

SuperVar::SuperVar(int ii) {
	vartype = integer;
	i = ii;
}

SuperVar::SuperVar(float ff) {
	vartype = floating_point;
	f = ff;
}

void SuperVar::print() {
	switch (vartype) {
	case character:
		std::cout << "character: " << c << "\n";
		break;
	case integer:
		std::cout << "integer: " << i << "\n";
		break;
	case floating_point:
		std::cout << "float: " << f << "\n";
		break;
	}
}

void _supervar() {
	SuperVar A('c'), B(12), C(1.44F);
	A.print();
	B.print();
	C.print();
	std::cout << "A size=> " << sizeof(A) << std::endl;
	std::cout << "B size=> " << sizeof(B) << std::endl;
	std::cout << "C size=> " << sizeof(C) << std::endl;
}