//: C01:Unexpected.cpp // Exception specifications & unexpected()
#pragma once
#include <exception>
#include <iostream>
#include <cstdlib>
// WORKS ONLY IN BCC32!!!
class Up {};
class Fit {};
void g();
// Optional exception handle SPECIFICATIONS:
void f(int i) throw (Up, Fit) { // List o'all types o' potential exceptions this func can throw.
	switch(i) {
		case 1: throw Up();
		case 2: throw Fit();
	}
	g(); // Throws somethin' unexpected (int)
}

static void no_throw() throw() {}; // Means no exceptions whatsoever'll be thrown from the func. Be sure no any other member func further down in the chain let any exception propagate up.
// void g() {} // Version 1
static void g() { throw 47; }
// Tip: Any time you use exception specifications or call functions that do, consider creating your
// own unexcpected() that logs a message and then either throws an exception or aborts the program.

static void my_unexpected() {
	std::cout << "unexpected exception thrown\n";
	// If it throws an exception o'type allowed by the function whose
	// specification was originally violated, the search resumes at the call o'the func.
	throw Fit();
	//std::exit(0);
}

static void _specification() {
	// Like set_terminate returns a ptr to a old_unexpected() to be restaured later.
	std::set_unexpected(my_unexpected); // Calls terminate()
	// (ignores return value)
	for(int i = 1; i <=3; i++) // Using' resumption
		try {
			f(i);
		} catch(Up) {
			std::cout << "Up caught\n";
		} catch(Fit) {
			std::cout << "Fit caught\n";
		} 
		//catch(...) {
		//	cout << "...\n";
		//}
} 