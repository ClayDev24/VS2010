// Constructors and destructors are quite unusual in that
// every single one in the hierarchy is called.
#pragma once
#include <iostream>

class Base {
public:
	Base()  { std::cout << "	Base()\n"; }
	~Base() { std::cout << "	~Base()\n"; }
};

class Derived:public Base {
public:
	Derived()  { std::cout << "	Derived()\n"; }
	~Derived() { std::cout << "	~Derived()\n"; }
};

class Other {
public:
	Other()  { std::cout << "	Other()\n"; }
	~Other() { std::cout << "	~Other()\n"; }
    Base b;
};

static void _destructor() {
	std::cout << "{\n"; 
	{
		Derived a;
		std::cout << "  ---\n";
		Other o;
		std::cout << "  ---\n";
	}
	std::cout << "}\n";
}