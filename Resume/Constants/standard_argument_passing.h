#pragma once
#include <iostream>

class X1 {};

X1 f() { return X1(); } // Return X obj by value

static void g1(X1&) {}		// Pass by non-const reference
static void g2(const X1&){} // Pass by     const reference

static void _standard_argument_passing() {
	// When you IMMEDIATELY take the return value of f() n' pass it to another function as in the calls to g1() and g2() a temporary is
	// created n' that temporary is *const. Thus, the call in g1() is an ERROR 'cuz g1() doesn't take a const reference, but the call to g2() is.
	g1(f()); // Error: const temporary created by f():
	g2(f()); // OK: g2 takes a const refereence:
}

//* Temporary objs is ALWAYS CONST!