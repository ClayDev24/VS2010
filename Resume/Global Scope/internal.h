#pragma once
#include <iostream>

int a = 30;
void f() { std::cout << "global f()\n"; }

struct S {
	int a;
	void f();
};

void S::f() {
	static int a = 0;
	std::cout << a++ << std::endl;
	//f();	// ERROR! Recursive!
	::f();	// global scope
	::a++;  // Select the global a
	a--;    // The a at struct scope
	std::cout << "internal f()\n"
		     << "::a = " << ::a << std::endl
		    << "a   = " << a    << std::endl;
}