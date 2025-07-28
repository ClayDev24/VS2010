#pragma once
#include <iostream>
// Handles exceptions from subobjects
class Base {
	int i;
public:
	class BaseExcept {};
	Base(int i):i(i) { throw BaseExcept(); }
};

class Derived : public Base {
public:
	class DerivedExcept {
		const char* msg;
	public:
		DerivedExcept(const char* msg) : msg(msg) {}
		const char* what() const { return msg; }
	};
	Derived(int j) try:Base(j) { // Constructor body
		std::cout << "This won't print\n";
	} catch(BaseExcept&) {
		throw DerivedExcept("Base subobject threw\n");;
	}
};
// Function Try Block:
static int func() try {
	throw "Function Try Block threw\n";
} catch(const char* msg) {
	std::cout << msg;
	return 1;
}

static void _function_try_block() {
	try {
		Derived d(3);
	} catch(Derived::DerivedExcept &d) {
		std::cout << d.what();  // "Base subobject threw"
	}
	func();
}