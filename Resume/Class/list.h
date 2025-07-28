#pragma once
#include <iostream>

class CList {
	const int c; // The place to put all const initializations is in the Constructor Initializer List shown below:
	int i, i2;
public:
	CList(int _c, int _i, int _i2): c(_c), i(_i), i2(_i2) {}// The list runs bfore any of the main constructor code is executed.
	void print() {
		std::cout << c << ", " << i << ", " << i2 << std::endl; 
	}
};

// Similarity of struct and class
struct A { // Defaults to public:
	void init(int _i);
private:
	int i;
};
void A::init(int _i) { i = _i; std::cout << i << std::endl; };

// Identical results are produced with:
class B { // Defaults to private:
	int i;
public:
	B(int i);
};
B::B(int _i) { i = _i; std::cout << i << std::endl; };

void _initializer_list();

static void _listUsage() {
	A a;		// struct declaration
	a.init(2);	// struct definition
	B b(3);		// class declaration/definition

	CList c1(1,2,3), c2(4,5,6);
	// The user-defined constructor style was 'extended' to build-in types:
	double pi(3.14159); // It simple measn assignment: float pi = 3.14159;
	
	c1.print(); c2.print();
	std::cout << pi << std::endl;
}

		   