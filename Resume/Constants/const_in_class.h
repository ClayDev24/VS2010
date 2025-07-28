// The compiler can ensure the constness of a built-in type but it cannot monitor the intricacies of a class. 
// To guarantee the constness of a class obj, the const member function is introduced:
// Only a const member function may be called for a const obj.

//:c08:ConstInitialization.cpp
// Initializaing const in classes
#pragma once
#include <iostream>
#define SIZE // Old C's style. Global visibility

class Fred {
	// Use const int inside classes instead old fashioned C's style #define. (The compiler treats all as globals from then on).
	// Meanings of const int defined inside a classe:
	// 1-Prevent global name clashes. 
	// 2-Allocate storage within each obj.
	// 3-Const for the lifetime o'obj.
	// 4-Each obj may contain a different value for it.
	const int size; //= 0; // Cannot be given an initial value. 
	char buf[];
public:
	// Must be initialized in the 'Initizlizer List' within the Constructor. It got to be already initilized when it reaches the body o'Constructor.
	Fred(int sz):size(sz) { buf[sz]; }
	inline void print() { std::cout << size << std::endl; }
};

// (2) User-defined constant:
class Y {
	int i;
public:
	Y(int ii):i(ii){};
	inline void f() {;};
	inline int  inc() { return i++; };
	// Only const member functions may be called for a const obj: To guarantee the constness of a class obj.
	void print() const;
};

static void _const_in_class() {
	Fred a(1), b(2), c(3);
	a.print(), b.print(), c.print();

	//(2) no const user-defined obj:
	Y y(10); const Y y1(20);
	y.print();
	y.inc();
	y.print();
	y1.print();
	//y1.inc(); // ERROR! Not allowe to call non const function members to const objs.
}