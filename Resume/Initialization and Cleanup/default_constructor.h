#pragma once
#include <iostream>
using std::cout;
using std::endl;

class NoDefault {
	int i;
public:
	// No default constructor (w/out args) provided...
	NoDefault(int _i):i(_i) { cout << "NoDefault(" << _i << ")\n"; }
	~NoDefault() { cout << "~NoDefault()\n"; } // Automatic called when by the compile when obj goes outta scope.
	inline void print() { cout << "NoDefault.i: " << i << endl; }
};
 
class Default {
	int i;
public:
	// Default constructor=> The one who be called w/no args.
	// Must be defined only if there are overloaded versions o'constructor like below
	Default():i(0){}
	Default(int _i):i(_i) { cout << "Default(" << _i << ")\n"; }
	~Default()   { cout << "~Default()\n"; } // Automatic called when by the compile when obj goes outta scope.
	inline void print() { cout << "Default.i: " << i << endl; }
};
 
class Auto {
	int i;
public:
	// Only if there aren't any constructor defined for a class
	// the compiler will automatically generates one for you.
	~Auto() { cout << "~Auto()\n"; } // Automatic called when by the compile when obj goes outta scope.
	inline void print() { cout << "Auto.i: " << i << "\n"; }
};
 
static void _default_constructor() {
	// OK! Overloaded constructor called:
	NoDefault n(2);
	n.print();
	// Errors! Must provide explicity default constructor:
	//NoDefault n1[2] = {NoDefault(33)};
	//NoDefault n2[7];
	//NoDefault n3;

	// Overloaded + default constructor provided:
	Default d1[2] = {Default(33)};
	Default d2[2];
	Default d3;
	d3.print(); // Memory explicity initialized by default constructor

	// Compiler automatically generates a default constructor:
	Auto a1[7];
	Auto a2;
	// It doesn't zero out memory.
	a2.print(); // Memory garbage
	// Hint: Always provides a default constructor explicity
	// n' initialize memo 2 some reasonable value, like zero.
}