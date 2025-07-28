#pragma once
#include <iostream>

int x,y; // globals
class enclose { // enclosing class
	int x; // note: private members
	static int s;
public:
	struct inner { // nested class
		void f(int i) {
			//x = i; // Error: can't write to non-static enclose::x without instance
			//int a = sizeof x; // Error until C++11,
			// OK in C++11: operand of sizeof is unevaluated,
			// this use of the non-static enclose::x is allowed.
			s = i;   // OK: can assign to the static enclose::s
			::x = i; // OK: can assign to global x
			y = i;   // OK: can assign to global y
		}

	private:
		void g() { std::cout << "g()..." << std::endl; }
	};
	void g(enclose* p, int i) {
		p->x = i; // OK: assign to enclose::x
	}
public:
	// ERROR: cannot access private member declared in class 
	//static inner f() { return inner::g(); }
};

static void _nestedUsage() {
//	enclose::inner n1 = enclose::f(); // error: 'nested' is private

	enclose::f().g(); // OK: does not name 'nested'
	auto n2 = enclose::f(); // OK: does not name 'nested'
	n2.g();
}