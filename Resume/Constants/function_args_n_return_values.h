#pragma once
#include <iostream>

static void _const_func_args(const int i) { //Useless cuz i is already a copy
	// Inside the function, the const takes on meaning: the arg cannot be changed:
	//i++; //ERROR
	// So, it's really a tool for the creator of the function, and not the caller.
}

// Useless for built-in types. Avoid to not confuse the client caller:
static const int test() {
	return 1;
}

static void _const_return_values() {
	int i = test();
}

// Returnin' const user-defined types by value:
class X {
	int i;
public:
	inline X(int _i = 0) { i = _i; }
	inline void modify() { i++;    }
};

X f5() { return X(); }

const X f6() { return X(); } // Returned const objs cannot be used as L-values

void f7(X& x) { x.modify(); }

static void test2() {
	f5() = X(1);	// OK -- non-const return value
	f5().modify();	// OK	
	f7(f5());       // Compiler creates an temporary obj to acomplish this, but all temps are made const by default to prevent you from modifying it. See Temporaries em pag 347 TICPP vol1
	// Causes compile-time errors:
	//f6() = X(1);   // L-value 
	//f6().modify(); // L-value n' try to change const obj
	//f7(f6());      // f7() modify the obj
	}

// Const pointer:

void t(int*) {} // t() accepts only non-constant pointers:

static void u2(const int* cip) { // u2() accepts both, const and non-constant pointers! It's more GENERAL!!
//! *cip = 2; // ERROR! Modifies values
	int i = *cip;
	//int *ip = cip; // ERROR! Non-const
	const int *ipc = cip;
}

static const char*v2() {
	// Return address of static character array:
	return "result of function v()"; // Compiler creates and stores a character array literal n' stores it in the STATIC Storage.
									 // It's technically a constant array, thuns the func return type.
}

// In return value, both the pointer n' what's it's pointin' to are constants:
static const int* const w2() {
	//int i = 33; // Returns garbage: Local static vars ares. Function exits and stack is cleaned'up.
	static int i = 33; // static vars don't evaluate after function exit
	return &i;
}

static void test3() {
	using namespace std;
	int x = 0;
	int *ip = &x;
	const int *cip = &x;
	t(ip);
	//t(cip);		// ERROR!
	u2(ip);
	u2(cip);
	//char *cp = v2(); // ERROR!
	const char *ccp = v2(); // Const OK!
	//int *ip2 = w2();	// ERROR!
	const int *const ccip = w2();
	cout << "Const ptr of int const ptr = " << *ccip << endl;
	const int *cip2 = w2();
	//*w2() = 1; // ERROR!
}