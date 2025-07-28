#pragma once
#include <iostream> // Overloading/Overriding functions:
// Can only be overloaded by arguments (types & number)
// Cannot be overloadef by return types! (TICPP v1 pag 313)
int   ret_val(int) {return 0;}		// @@ret_val$qi
// Errors:
//char  ret_val(int) {return 'c';}	// @@ret_val$qi
//float ret_val(int) {return 5.5f;}	// @@ret_val$qi

// Global func overloading:
static void print(char);	// @@print$qc
static void print(float);	// @@print$qf

class Y {
public:
	// Member class func overloading:
	void print(char);	// @@Y@print$qc
	void print(float);	// @@Y@print$qf
};

void Y::print(char c) {
	std::cout << c << std::endl;
}

void Y::print(float f) {
	std::cout << f << std::endl;
}

static void print(char c) {
	std::cout << c << std::endl;
}

static void print(float f) {
	std::cout << f << std::endl;
}

// C++ name decoration provides a safety net called "Type-safe linkage".
static void _overloading() {
	// Global overloading:
	print('a');
	print(5.5f);
	// Local (class) scope overloading:
	Y y;
	y.print('b');
	y.print(6.6f);
}