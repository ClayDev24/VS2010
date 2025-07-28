// For uncaught exceptions. Two basic models in exception handling: Termination and resumption.
// C++ supports termination. To implemente resumption in C++ use the followin'tecnique.
#pragma once
#include <exception>
#include <iostream>
#include <cstdlib>
// The default terminate() calls the abort()
// which means that destructors for local and static objs DO NOT execute.
// Func to overwrites the default terminate func, as below:
static void terminator() { // Unrecoverable from this point on:
	cout << "Terminate(""Uncaugh exception"")\n";
	exit(0); // NOT abrupty terminates the program. 
}

// Pointer fo function used to restore the old default terminator functio at will:
void (*old_terminate)() = set_terminate(terminator);

class Botch {
public:
	class Fruit {};
	void f() {
		cout << "Botch::f()\n";
		throw Fruit();
	}
	// Let a constructor/destructor trhows an exception is always a bad practice (Poor design || sloppy coding).
	~Botch() { 
		cout << "~Botch()\n";
		//Throwin'an exception(in destructor) while stack's unwindin' cause the call 2 a terminate().
		throw 'c';
	}
};

static void _terminate() {
	using std::cout;
	//set_terminate(terminator); // Sets a new func to be called without savin' the old one ptr.
	try {
		// Not call terminate() for local heap allocated objs:
		//Botch *b = new Botch();
		//b->f();
		Botch b; // Jus'for local static ones
		b.f();
	} catch(...) {
	//} catch(const int &ex) { // If no matchs auto-calls the terminator()
		cout << "inside catch(...)\n";
	}
	set_terminate(old_terminate); // To restore the old.
} ///:~
