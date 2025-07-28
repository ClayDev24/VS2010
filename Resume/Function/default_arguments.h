#pragma once
#include <iostream>
// Default Arguments: A val tha is more likely to occur
class DefArgs {
	int i;
	int i2;
public:
	// 1- Used to unify different functions w/ similar signatures and similar behaviors:
	// Must be placed in prototypes in header files. Can also be placed in definition code in cpp files (4 doc purposes)
	//Default(int _i)           :i(_i), i2(0)   {}
	//Default(int _i, int _i2)  :i(_i), i2(_i2) {}
	DefArgs(int _i, int _i2=0):i(_i), i2(_i2) {} // Only 1 func instead of 2 above
	// Only trailin'args must be defaulted:
	//DefError1(int i=0, int i2) {}

	// 2- Placeholder Arguments (def args w/out identifiers):
	void PlaceHolder(int i, int=0, float=0.1);

	~DefArgs() { std::cout << "~DefArgs()\n"; }
	inline void print() { std::cout << "i:" << i << ", i2:" << i2 << std::endl; }
};

// C++ Unnamed default arguments in definition:
// Reserves space w/out disturbing any existing code + Suppress warnings
void DefArgs::PlaceHolder(int _i, int /*_i2*/, float _f) {
	std::cout << "i : " << _i  << "\n";
	//std::cout << "i2: " << _i2 << "\n";
	std::cout << "f : " << _f  << "\n\n";
}

static void _default_arguments() {
	// Calls to the same function:
	DefArgs a(5);
	DefArgs b(5, 6);
	a.print();
	b.print();

	a.PlaceHolder(1);		  // (1, 0, 0.2)
	a.PlaceHolder(1, 2);	  // (1, 2, 0.3)
	a.PlaceHolder(1, 2, 3.3f);// (1, 2, 3.3)
	a.PlaceHolder(1, 3.3f);	  // (1, 3, 0.3) // #2 casted to an int
}