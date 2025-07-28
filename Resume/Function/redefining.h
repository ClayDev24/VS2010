// In general, everytime you redefine an overloaded function name from the base class,
// all other versions are automatically hidden.
#pragma once
#include <iostream>
#include <string>

class Base {
public:
	int f() const { // normal function
		std::cout << "Base::f()\n"; 
		return 1; 
	}
	inline int f(std::string) const { return 1; } // overloading function
	inline void g() {}
};

class Derived1 : public Base {
public:
	inline void g() const {} // redefined function. Changes func signature
};

class Derived2 : public Base {
public:
	// Redefines Base::f(), hides all overloaded versions
	inline int f() const { 
		std::cout << "Derived2::f()\n"; 
		return 2;
	}
};

class Derived3 : public Base {
public:
	//Changin' return type hides all Base versions:
	inline void f() const { std::cout << "Derived3::f()\n"; }
};

class Derived4 : public Base {
public:
	// Changin' args list hides all Base versions:
	inline int f(int) const { 
		std::cout << "Derived4::f()\n"; 
		return 4; 
	}
};

static void _redefining() {
	std::string s("hello");
	Derived1 d1;
	int x = d1.f();
	d1.f(s);
	Derived2 d2;
	x = d2.f();
	// d2.f(s);	 // std::string version hidden
	Derived3 d3;
	d3.f(); // Redefined func.
	// x = d3.f(); // return int version hidden
	// d3.f(s);    // std::string args version hidden
	Derived4 d4;
	//!  x = d4.f(); // f() version hidden
	x = d4.f(1);
	//d4.f("hehe"); // Hidden version
}