//**** IMPORTANTE**** MUST ENABLE RTTI (ALT+F7) Category: C++ Language!
#pragma once
#include <iostream>
#include <typeinfo.h>
#include <stdio.h>
using namespace std;

class CVehicle {
public:
	CVehicle() { std::cout << "CVehicle()...\n"; };
	virtual ~CVehicle() {}; // polimorphic class must have at least one virtual function.	
};

class CCar:public CVehicle {
public:
	CCar() { std::cout << "CCar()...\n"; };
	virtual ~CCar() {};
	inline void aa() { std::cout << "aa\n"; };
};

static void _rtti2() {
	CVehicle *v = new CVehicle();
	CCar     *c = new CCar();
	CVehicle *v1 = 0;
	CCar     *c1 = NULL;

	// upcast (car to vehicle):
	v1 = dynamic_cast<CVehicle*>(c);
	// downcast (vehicle to car):
	c1 = dynamic_cast<CCar*>(v);
	if(c1) {
		std::cout << "It is a car!\n";
		c1->aa(); // Safe to call aa()..
	}
	delete v;
	delete c;
}