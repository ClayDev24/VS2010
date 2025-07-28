//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
// "Casting away" constness Vs. Mutable
class Y {
	int i;
public:
	Y():i(0) {};
	void f() const; // Lack o'constness is hidden in interface class.
};

void Y::f() const { // Logical const
	//!  i++; // Error -- const member function
	((Y*)this)->i++; // OK: cast away const-ness. Used mostly in legacy code.
	// Better: use C++ explicit cast syntax:
	(const_cast<Y*>(this))->i++;
}

class Z {
	int i;
	mutable int j; // Visible to users o'tha class tha this var is subject to change
public:
	Z():i(0), j(0) {};
	void f() const;
};

void Z::f() const {
	//! i++; // Error -- const member function
	// (const_cast<Z*>(this))->i++;  // 
    j++; // OK: mutable
}

int main() {
	const Y yy;
	yy.f(); // Actually changes it!

	const Z zz;
	zz.f(); // Actually changes it!

	system("pause");
	return(0);
} ///:~
